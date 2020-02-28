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

int send_fd(int ufd, struct sockaddr_un *servaddr, void *data, int dataLen, int fd)
{
    struct msghdr msg = { 0 };
    struct iovec vec = { 0 };
    union {
        struct cmsghdr cm;
        char control[CMSG_SPACE(sizeof(int))];
    } control_un;
    struct cmsghdr *cmptr;

    msg.msg_control = control_un.control;
    msg.msg_controllen = sizeof(control_un.control);

    cmptr = CMSG_FIRSTHDR(&msg);
    cmptr->cmsg_len = CMSG_LEN(sizeof(int));
    cmptr->cmsg_level = SOL_SOCKET;
    cmptr->cmsg_type = SCM_RIGHTS;
    *((int*)CMSG_DATA(cmptr)) = fd;

    msg.msg_name = servaddr;
    msg.msg_namelen = sizeof(struct sockaddr_un);

    vec.iov_base = data;
    vec.iov_len = dataLen;
    msg.msg_iov = &vec;
    msg.msg_iovlen = 1;

    int n = 0;
    while (1) {
        fprintf(stdout, "start to send fd\n");
        n = sendmsg(ufd, &msg, 0);
        if(n < 0) {
            if(errno == EINTR) {
                continue;
            } else {
                fprintf(stderr, "send fd error, reason: %s\n", strerror(errno));
                return -1;
            }
        }

        else if(n == 0) {
            fprintf(stderr, "send zero bytes\n");
            return -1;
        } else {
            return n;
        }
    }
}

int main(int argc, char *argv[])
{
    int opt;
    int count = 1;
    while ((opt = getopt(argc, argv, "c:")) != -1) {
        switch (opt) {
        case 'c':
            count = atoi(optarg);
            break;
        default:
            break;
        }
    }

    int usock = -1;
    struct sockaddr_un servaddr;
    bzero(&servaddr, sizeof(servaddr));

    servaddr.sun_family = AF_UNIX;
    strncpy(servaddr.sun_path, "/tmp/UnixSock_Test", sizeof(servaddr.sun_path) - 1);

    if ((usock = socket(AF_UNIX, SOCK_DGRAM, 0)) < 0) {
        err_quit("create unix sock failed", errno);
    }

    struct timeval tv = { 10, 0 };
    if (setsockopt(usock, SOL_SOCKET, SO_SNDTIMEO, (char *)&tv, sizeof(tv)) < 0) {
        err_quit("setsockopt failed", errno);
    }

    int fd = STDIN_FILENO;
    while (count--) {
        fprintf(stdout, "ret: %d\n", send_fd(usock, &servaddr, &fd, sizeof(fd), fd));
    }

    exit(0);
}
