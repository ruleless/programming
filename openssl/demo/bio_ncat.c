#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <errno.h>
#include <sys/epoll.h>
#include <openssl/crypto.h>
#include <openssl/bio.h>

#define MAX_EVENTS 64
#define SOCKADDR_LEN 32

typedef struct server_s server_t;
typedef struct connection_s connection_t;

struct connection_s
{
    int fd;
};

struct server_s
{
    connection_t conn;

    int ep_fd;
};

static BIO *g_err_bio;

static server_t *server_init(char *bindaddr);
static void server_loop(server_t *s);
static connection_t *accept_client(server_t *s);

static server_t *server_init(char *bindaddr)
{
    server_t *s = NULL;
    struct epoll_event ev;

    s = OPENSSL_malloc(sizeof(*s));
    if (!s)
    {
        BIO_printf(g_err_bio, "malloc server failed\n");
        return NULL;
    }

    s->ep_fd = epoll_create(20);
    if (s->ep_fd < 0)
    {
        BIO_printf(g_err_bio, "epoll_create failed, %s\n", strerror(errno));
        goto err_1;
    }
    s->conn.fd = BIO_get_accept_socket(bindaddr, 0);
    if (s->conn.fd < 0)
    {
        BIO_printf(g_err_bio, "create listen socket failed, %s\n", strerror(errno));
        goto err_2;
    }

    ev.data.ptr = s;
    ev.events = EPOLLIN;
    if (epoll_ctl(s->ep_fd, EPOLL_CTL_ADD, s->conn.fd, &ev) < 0)
    {
        BIO_printf(g_err_bio, "add read event failed, %s\n", strerror(errno));
        goto err_2;
    }

    return s;

err_2:
    if (s->conn.fd >= 0)
        close(s->conn.fd);
err_1:
    if (s->ep_fd >= 0)
        close(s->ep_fd);
    if (s)
        OPENSSL_free(s);

    return NULL;
}

static void server_loop(server_t *s)
{
    struct epoll_event evs[MAX_EVENTS];
    connection_t *conn;
    int n, i;

    for (;;)
    {
        n = epoll_wait(s->ep_fd, evs, MAX_EVENTS, -1);

        if (n < 0)
        {
            if (EINTR == errno)
            {
                continue;
            }
            else
            {
                BIO_printf(g_err_bio, "fatal error, %s", strerror(errno));
                return;
            }
        }

        for (i = 0; i < n; i++)
        {
            conn = (connection_t *)evs[i].data.ptr;
            if (conn->fd == s->conn.fd)
            {
                accept_client(s);
            }
        }
    }
}

static connection_t *accept_client(server_t *s)
{
    int connfd = -1;
    connection_t *conn = NULL;
    char *cliaddr = NULL;

    if ((connfd = BIO_accept(s->conn.fd, &cliaddr)) < 0)
    {
        BIO_printf(g_err_bio, "accept failed, %s\n", strerror(errno));
        return NULL;
    }

    conn = OPENSSL_malloc(sizeof(*conn));
    if (!conn)
    {
        goto err_1;
    }
    conn->fd = connfd;

    return conn;

err_1:
    if (connfd >= 0)
        close(connfd);

    return NULL;
}

int main(int argc, char *argv[])
{
    int opt = 0, port = -1;
    const char *addr = "127.0.0.1";
    char servaddr[SOCKADDR_LEN] = {0};
    server_t *server;

    g_err_bio = BIO_new_fp(stderr, BIO_NOCLOSE);
    if (!g_err_bio)
    {
        fprintf(stderr, "new error bio failed.\n");
        exit(1);
    }

    while ((opt = getopt(argc, argv, "l:p:")) != -1)
    {
        switch (opt)
        {
        case 'l':
            addr = optarg;
            break;
        case 'p':
            port = atoi(optarg);
            break;
        default:
            break;
        }
    }

    if (port <= 0 || port >= 65535)
    {
        BIO_printf(g_err_bio, "no port specified.\n");
        exit(1);
    }
    snprintf(servaddr, sizeof(servaddr), "%s:%d", addr, port);

    if ((server = server_init(servaddr)) < 0)
    {
        BIO_printf(g_err_bio, "init server failed\n");
        exit(1);
    }
    server_loop(server);

    exit(0);
}
