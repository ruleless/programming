#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <sys/un.h>
#include <arpa/inet.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

static int recv_fd(int ufd, char *buf, int buflen)
{
    struct msghdr msg;
    struct iovec iov;
    char ccmsg[CMSG_SPACE(sizeof(int))];
    struct cmsghdr *cmsg;

    iov.iov_base = buf;
    iov.iov_len = buflen;

    msg.msg_name = 0;
    msg.msg_namelen = 0;
    msg.msg_iov = &iov;
    msg.msg_iovlen = 1;
    msg.msg_control = ccmsg;
    msg.msg_controllen = sizeof(ccmsg);

again:
    if (recvmsg(ufd, &msg, 0) < 0) {
        if (errno == EINTR) {
            goto again;
        }

        fprintf(stderr, "recvmsg error, reason: %s\n", strerror(errno));
        return -1;
    }

    cmsg = CMSG_FIRSTHDR(&msg);

    if (cmsg && cmsg->cmsg_len == CMSG_LEN(sizeof(int))) {
        if (cmsg->cmsg_level == SOL_SOCKET && cmsg->cmsg_type == SCM_RIGHTS) {
            memcpy(buf, msg.msg_iov[0].iov_base, msg.msg_iov[0].iov_len);
            return *(int *)CMSG_DATA(cmsg); // fd
        }
    }

    fprintf(stderr, "null CMSG_FIRSTHDR\n");
    return -1;
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
                sleep(5);
                char buf[64];
                int fd = recv_fd(events[i].data.fd, buf, sizeof(buf));
                if (fd >= 0) {
                    fprintf(stdout, "recv fd: %d\n", fd);
                }
            }
        }
    }

    exit(0);
}
