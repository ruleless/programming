#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/epoll.h>

#define MAX_EVENTS 10

static int setnonblocking(int fd)
{
    int flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        return -1;
    }
    if (fcntl(fd, F_SETFL, flag | O_NONBLOCK) < 0) {
        return -1;
    }
    return 0;
}

static void echo(int fd)
{
    char buf[4096], addrtext[INET_ADDRSTRLEN] = {0};
    const char *bufptr;
    int n, left, sent;
    struct sockaddr_in cli_addr;
    socklen_t addrlen;

    for (;;) {
        n = read(fd, buf, sizeof(buf));
        if (n < 0) {
            if (errno == EINTR) {
                continue;
            } else if (errno == EAGAIN || errno == EWOULDBLOCK) {
                break; /* read next time */
            }

            perror("read from client error");
            close(fd);
            break; /* occur error */
        } else if (n == 0) {
            if (getpeername(fd, (struct sockaddr *)&cli_addr, &addrlen) == 0) {
                inet_ntop(AF_INET, &cli_addr.sin_addr, addrtext, sizeof(addrtext));
                fprintf(stderr, "client closed, client: %s:%d\n",
                        addrtext, ntohs(cli_addr.sin_port));
            } else {
                fprintf(stderr, "client closed\n");
            }

            close(fd);
            break; /* connection closed */
        }

        /* n > 0 */

        bufptr = buf;
        left = n;

  write_again:
        sent = write(fd, bufptr, left);
        if (sent < 0) {
            if (errno == EINTR) {
                goto write_again;
            } else if (errno == EAGAIN || errno == EWOULDBLOCK) {
                goto write_again;
            }

            perror("write to client error");
            break; /* occur error */
        }

        left -= sent;
        if (left > 0) {
            bufptr += sent;
        }
    }
}

int main(int argc, char *argv[])
{
    struct epoll_event ev, events[MAX_EVENTS];
    int epollfd, listen_sock, conn_sock;
    int nfds, n;
    struct sockaddr_in servaddr, addr;
    socklen_t addrlen;

    /* create socket */
    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        perror("create listen sock err");
        exit(EXIT_FAILURE);
    }

    /* bind server address */
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(60000);
    if (bind(listen_sock, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind addr err");
        exit(EXIT_FAILURE);
    }

    if (listen(listen_sock, 5) < 0) {
        perror("listen err");
        exit(EXIT_FAILURE);
    }

    /* call epoll */
    epollfd = epoll_create1(0);
    if (epollfd == -1) {
        perror("epoll_create1");
        exit(EXIT_FAILURE);
    }

    ev.events = EPOLLIN;
    ev.data.fd = listen_sock;
    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, listen_sock, &ev) == -1) {
        perror("epoll_ctl: listen_sock");
        exit(EXIT_FAILURE);
    }

    /* event loop */
    for (;;) {
        nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
        if (nfds == -1) {
            perror("epoll_wait");
            exit(EXIT_FAILURE);
        }

        for (n = 0; n < nfds; ++n) {
            if (events[n].data.fd == listen_sock) {
                conn_sock = accept(listen_sock,
                                   (struct sockaddr *)&addr, &addrlen);
                if (conn_sock == -1) {
                    perror("accept");
                    exit(EXIT_FAILURE);
                }

                /* test: 预读部分数据后，看是否还能触发事件 */
                char tmpbuf[4] = {0};
                int recvlen = read(conn_sock, tmpbuf, sizeof(tmpbuf) - 1);
                if (recvlen > 0) {
                    printf("preread: %s\n", tmpbuf);
                    write(conn_sock, tmpbuf, recvlen);
                }

                setnonblocking(conn_sock);

                ev.events = EPOLLIN | EPOLLET;
                ev.data.fd = conn_sock;
                if (epoll_ctl(epollfd, EPOLL_CTL_ADD, conn_sock,
                              &ev) == -1) {
                    perror("epoll_ctl: conn_sock");
                    exit(EXIT_FAILURE);
                }
            } else {
                echo(events[n].data.fd);
            }
        }
    }

    return 0;
}
