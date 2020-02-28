// accept but no recv

#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_BUF 1024
#define ECHO_MSG "Hello World"

typedef struct sockaddr SA;

static void err_quit(const char *msg, int err)
{
	const char *s_err = strerror(err);
	if (NULL == s_err) {
		s_err = "";
	}
	printf("%s %s\n", msg, s_err);
	exit(1);
}

static void set_nonblocking(int sock)
{
    int opts = fcntl(sock, F_GETFL);;
    if(opts < 0) {
        err_quit("fcntl(sock,GETFL)", errno);
    }

    opts = opts | O_NONBLOCK;
    if(fcntl(sock, F_SETFL, opts) < 0) {
        err_quit("fcntl(sock,SETFL,opts)", errno);
    }
}

int main(int argc, char *argv[])
{
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if (listenfd < 0) {
		err_quit("create listen fd err!", errno);
	}

    int opt;
    int port = 60000;
    while ((opt = getopt(argc, argv, "p:")) != -1) {
        switch (opt) {
        case 'p':
            port = atoi(optarg);
            break;
        default:
            break;
        }
    }

    struct sockaddr_in servaddr;
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(60000);

	if (bind(listenfd, (const SA*)&servaddr, sizeof(servaddr)) < 0) {
		err_quit("bind err!", errno);
	}

	if (listen(listenfd, 5) < 0) {
		err_quit("listen err!", errno);
	}

    char buf[MAX_LINE_BUF + 1];
    struct epoll_event ev, events[20];
    int epfd = epoll_create(256);

    set_nonblocking(listenfd);
    ev.data.fd = listenfd;
    ev.events = EPOLLIN | EPOLLET;
    epoll_ctl(epfd, EPOLL_CTL_ADD, listenfd, &ev);

    for (;;) {
        struct sockaddr_in cliaddr;
        socklen_t cliaddr_len;
        int nfds = epoll_wait(epfd, events, 20, 500);
        int i, n;

        for (i = 0; i < nfds; i++) {
            if(events[i].data.fd == listenfd) {
                int connfd = accept(listenfd, (SA *)&cliaddr, &cliaddr_len);
                if(connfd < 0) {
                    fprintf(stderr, "accept failed, reason: %s\n", strerror(errno));
                }

                set_nonblocking(connfd);

                // ev.data.fd = connfd;
                // ev.events = EPOLLIN | EPOLLET;
                // epoll_ctl(epfd, EPOLL_CTL_ADD, connfd, &ev);

            } else if (events[i].events & EPOLLIN) {
                int sockfd = events[i].data.fd;
                if (sockfd < 0) {
                    continue;
                }

          again:
                n = read(sockfd, buf, MAX_LINE_BUF);
                if (n < 0) {
                    if (errno == EINTR || errno == EAGAIN) {
                        goto again;
                    }

                    fprintf(stderr, "recv error, fd: %d, reason: %s\n", sockfd, strerror(errno));
                    close(sockfd);
                    events[i].data.fd = -1;
                    continue;

                } else if (n == 0) {
                    fprintf(stderr, "connectin closed, fd: %d\n", sockfd);
                    close(sockfd);
                    events[i].data.fd = -1;
                    continue;
                }

                write(sockfd, ECHO_MSG, sizeof(ECHO_MSG) - 1);

                ev.data.fd = sockfd;
                ev.events = EPOLLOUT | EPOLLET;
                epoll_ctl(epfd, EPOLL_CTL_MOD, sockfd, &ev);
            }
        }
    }

    exit(0);
}
