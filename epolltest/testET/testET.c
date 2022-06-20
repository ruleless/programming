#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
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

int main(int argc, char *argv[])
{
    struct epoll_event ev, events[MAX_EVENTS];
    int epollfd, listen_sock, conn_sock;
    int nfds, n;
    struct sockaddr_in servaddr, addr;
    socklen_t addrlen;

    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        perror("create listen sock err");
        exit(EXIT_FAILURE);
    }

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

                setnonblocking(conn_sock);
                ev.events = EPOLLIN | EPOLLET;
                ev.data.fd = conn_sock;
                if (epoll_ctl(epollfd, EPOLL_CTL_ADD, conn_sock,
                              &ev) == -1) {
                    perror("epoll_ctl: conn_sock");
                    exit(EXIT_FAILURE);
                }
            } else {
                // do_use_fd(events[n].data.fd);
            }
        }
    }

    return 0;
}
