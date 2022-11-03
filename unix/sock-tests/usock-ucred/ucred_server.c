#define _GNU_SOURCE

#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <sys/un.h>
#include <arpa/inet.h>

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Resolves to a type that can carry cmsghdr structures. Make sure things are properly aligned, i.e. the type
 * itself is placed properly in memory and the size is also aligned to what's appropriate for "cmsghdr"
 * structures. */
#define CMSG_BUFFER_TYPE(size)                                      \
    union {                                                         \
        struct cmsghdr cmsghdr;                                     \
        uint8_t buf[size];                                          \
        uint8_t align_check[(size) >= CMSG_SPACE(0) &&              \
                            (size) == CMSG_ALIGN(size) ? 1 : -1];   \
    }

#define CMSG_FOREACH(cmsg, mh)                                          \
    for ((cmsg) = CMSG_FIRSTHDR(mh); (cmsg); (cmsg) = CMSG_NXTHDR((mh), (cmsg)))

static void err_quit(const char *msg, int err)
{
    const char *s_err = strerror(err);
    if (NULL == s_err) {
        s_err = "";
    }
    printf("%s %s\n", msg, s_err);
    exit(1);
}

static int create_unix_socket(const char *fname, int type, int timeout)
{
    int sock = -1;
    struct sockaddr_un servaddr;
    bzero(&servaddr, sizeof(servaddr));

    if (fname == NULL) {
        return -1;
    }

    servaddr.sun_family = AF_UNIX;
    strncpy(servaddr.sun_path, fname, sizeof(servaddr.sun_path) - 1);

    if ((sock = socket(AF_UNIX, type, 0)) < 0) {
        return -1;
    }

    struct timeval tv = { timeout, 0 };
    if (setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (char *)&tv, sizeof(tv)) < 0) {
        return -1;
    }

    unlink(fname);

    if (bind(sock, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        close(sock);
        return -1;
    }

    if (type == SOCK_STREAM) {
        if ((listen(sock, 5)) < 0) {
            close(sock);
            return -1;
        }
    }

    if (chmod(fname, 0777) < 0) {
        close(sock);
        return -1;
    }

    return sock;
}

static void recv_ucred(int ufd)
{
    char buf[512];
    struct iovec iovec = {
        .iov_base = buf,
        .iov_len = sizeof(buf)-1,
    };
    CMSG_BUFFER_TYPE(CMSG_SPACE(sizeof(struct ucred)) +
                     CMSG_SPACE(sizeof(int)))control;
    struct msghdr msghdr = {
        .msg_iov = &iovec,
        .msg_iovlen = 1,
        .msg_control = &control,
        .msg_controllen = sizeof(control),
    };

    struct cmsghdr *cmsg;
    struct ucred *ucred;
    int n;

again:
    n = recvmsg(ufd, &msghdr, MSG_DONTWAIT|MSG_CMSG_CLOEXEC);
    if (n < 0) {
        if (errno == EINTR) {
            goto again;
        }

        fprintf(stderr, "recvmsg error, reason: %s\n", strerror(errno));
        return;
    }
    buf[n] = '\0';

    CMSG_FOREACH(cmsg, &msghdr) {
        if (cmsg->cmsg_level == SOL_SOCKET && cmsg->cmsg_type == SCM_RIGHTS) {
            fprintf(stdout, "recv fd: %d\n", *(int *)CMSG_DATA(cmsg));
        } else if (cmsg->cmsg_level == SOL_SOCKET &&
                   cmsg->cmsg_type == SCM_CREDENTIALS &&
                   cmsg->cmsg_len == CMSG_LEN(sizeof(struct ucred)))
        {
            ucred = (struct ucred *)CMSG_DATA(cmsg);
            fprintf(stdout, "<pid: %z, uid: %z, %gid: %z> ",
                    ucred->pid, ucred->uid, ucred->gid);
        } else {
            fprintf(stderr, "unknwon control message\n");
        }
    }
    fprintf(stdout, "%s\n", buf);
}

int main(int argc, char *argv[])
{
    int ufd = -1;
    int ep_fd = -1;
    int r = 0, i, n;
    char buf[1024];
    struct epoll_event ev;
    struct epoll_event events[20];

    ep_fd = epoll_create(20);
    if (ep_fd < 0) {
        err_quit("epoll_create failed", errno);
    }

    unlink("/tmp/UnixSock_Test");
    ufd = create_unix_socket("/tmp/UnixSock_Test", SOCK_DGRAM, 10);
    if (ufd < 0) {
        err_quit("create unix socket failed", errno);
    }

    ev.data.fd = ufd;
    ev.events = EPOLLIN;
    r = epoll_ctl(ep_fd, EPOLL_CTL_ADD, ufd, &ev);
    if (r < 0) {
        err_quit("add in event failed", errno);
    }

    while (1) {
        r = epoll_wait(ep_fd, events, sizeof(events) / sizeof(events[0]), -1);

        if (r < 0) {
            if (EINTR == errno) {
                continue;
            } else {
                err_quit("fatal error", errno);
            }
        }

        for (i = 0; i < r; i++) {
            if (events[i].events | EPOLLIN) {
                recv_ucred(events[i].data.fd);
            }
        }
    }

    return 0;
}
