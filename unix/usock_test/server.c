#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <sys/un.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/epoll.h>

static int set_nonblock(int fd)
{
    int flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0)
    {
        return -1;
    }
    if (fcntl(fd, F_SETFL, flag | O_NONBLOCK) < 0)
    {
        return -1;
    }
    return 0;
}

static int create_unix_socket_nonblock(const char *fname, int type)
{
    int sock = -1;
    struct sockaddr_un servaddr;
    bzero(&servaddr, sizeof(servaddr));

    if (NULL == fname)
    {
        return -1;
    }

    servaddr.sun_family = AF_UNIX;
    strncpy(servaddr.sun_path, fname, sizeof(servaddr.sun_path) - 1);

    if ((sock = socket(AF_UNIX, type, 0)) < 0)
    {
        return -1;
    }

    unlink(fname);

    if (bind(sock, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        close(sock);
        return -1;
    }

    if (type == SOCK_STREAM)
    {
        if ((listen(sock, 5)) < 0)
        {
            close(sock);
            return -1;
        }
    }

    if (set_nonblock(sock) < 0)
    {
        close(sock);
        return -1;
    }

    if (chmod(fname, 0777) < 0)
    {
        close(sock);
        return -1;
    }
    return sock;
}

int main(int argc, char *argv[])
{
    int usock_fd = -1;
    int ep_fd = -1;
    int r = 0, i, n;
    char buf[1024];
    struct epoll_event ev;
    struct epoll_event events[20];

    ep_fd = epoll_create(20);
    if (ep_fd < 0)
    {
        fprintf(stderr, "epoll_create failed, %s\n", strerror(errno));
        goto err_1;
    }

    unlink("/tmp/UnixSock_Test");
    usock_fd = create_unix_socket_nonblock("/tmp/UnixSock_Test", SOCK_DGRAM);
    if (usock_fd < 0)
    {
        fprintf(stderr, "create unix socket failed, %s\n", strerror(errno));
        goto err_2;
    }

    ev.data.fd = usock_fd;
    ev.events = EPOLLIN;
    r = epoll_ctl(ep_fd, EPOLL_CTL_ADD, usock_fd, &ev);
    if (r < 0)
    {
        fprintf(stderr, "add in event failed, %s\n", strerror(errno));
        goto err_2;
    }

    while (1)
    {
        usleep(10*1000);
        r = epoll_wait(ep_fd, events, sizeof(events) / sizeof(events[0]), -1);

        if (r < 0)
        {
            if (EINTR == errno)
            {
                continue;
            }
            else
            {
                fprintf(stderr, "fatal error, %s\n", strerror(errno));
                exit(1);
            }
        }

        for (i = 0; i < r; i++)
        {
            if (events[i].events | EPOLLIN)
            {
                n = recv(events[i].data.fd, buf, sizeof(buf) - 1, 0);
                buf[n - 1] = '\0';
                fprintf(stdout, "recv:%s\n", buf);
            }
        }
    }

err_2:
    if (usock_fd >= 0)
        close(usock_fd);
err_1:
    if (ep_fd >= 0)
        close(ep_fd);

    exit(0);
}
