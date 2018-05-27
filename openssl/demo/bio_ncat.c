#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
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
    server_t *svr;
    char *peer_addr;

    connection_t *prev;
    connection_t *next;

    int (*handler)(connection_t *conn, int events);
};

struct server_s
{
    connection_t conn;

    int ep_fd;
};

static BIO *g_err_bio;
static int g_exit_loop;

static server_t *server_init(char *bindaddr);
static void server_loop(server_t *s);
static void server_exit(server_t *s);
static int accept_client(connection_t *conn, int events);
static int echo_client(connection_t *conn, int events);

static void sig_int(int signo)
{
    g_exit_loop = 1;
}

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
    s->conn.fd = BIO_get_accept_socket(bindaddr, BIO_BIND_REUSEADDR);
    if (s->conn.fd < 0)
    {
        BIO_printf(g_err_bio, "create listen socket failed, %s\n", strerror(errno));
        goto err_2;
    }
    if (set_nonblock(s->conn.fd) < 0)
    {
        BIO_printf(g_err_bio, "set nonblock failed\n");
        goto err_2;
    }
    s->conn.svr = s;
    s->conn.handler = accept_client;
    s->conn.peer_addr = NULL;
    s->conn.prev = s->conn.next = NULL;

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

    while (!g_exit_loop)
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
            conn->handler(conn, evs[i].events);
        }
    }
}

static void server_exit(server_t *s)
{
    connection_t *conn = s->conn.next, *next;

    while (conn)
    {
        next = conn->next;
        close(conn->fd);
        BIO_printf(g_err_bio, "free client: %s\n", conn->peer_addr);
        OPENSSL_free(conn->peer_addr);
        OPENSSL_free(conn);
        conn = next;
    }
    close(s->conn.fd);
    close(s->ep_fd);
    OPENSSL_free(s);
}

static int accept_client(connection_t *conn, int events)
{
    int connfd = -1;
    connection_t *inconn = NULL;
    server_t *s = (server_t *)conn;
    struct epoll_event ev;
    char *cliaddr = NULL;

    if ((connfd = BIO_accept(conn->fd, &cliaddr)) < 0)
    {
        BIO_printf(g_err_bio, "accept failed, %s\n", strerror(errno));
        return -1;
    }

    inconn = OPENSSL_malloc(sizeof(*inconn));
    if (!inconn)
    {
        goto err_1;
    }
    if (set_nonblock(connfd) < 0)
    {
        goto err_1;
    }
    inconn->fd = connfd;
    inconn->svr = s;
    inconn->peer_addr = cliaddr;
    inconn->handler = echo_client;
    inconn->next = conn->next;
    inconn->prev = conn;
    conn->next = inconn;

    ev.events = EPOLLIN;
    ev.data.ptr = inconn;
    if (epoll_ctl(s->ep_fd, EPOLL_CTL_ADD, connfd, &ev) < 0)
    {
        goto err_2;
    }

    return 0;

err_2:
    if (inconn)
        OPENSSL_free(inconn);
err_1:
    if (connfd >= 0)
        close(connfd);

    return -1;
}

static int echo_client(connection_t *conn, int events)
{
    server_t *s = conn->svr;
    struct epoll_event ev;
    char buf[256];
    int n;

    if (events | EPOLLIN)
    {
  again:
        n = read(conn->fd, buf, sizeof(buf) - 1);

        if (n < 0 && EINTR == errno)
        {
            goto again;
        }
        else if (n == 0)
        {
            BIO_printf(g_err_bio, "client shutdown, fd=%d\n", conn->fd);
            goto shut;
        }

        buf[n] = '\0';
        fprintf(stdout, "%s", buf);
    }
    else if (events | EPOLLERR)
    {
        goto shut;
    }

    return 0;

shut:
    ev.events = EPOLLIN;
    epoll_ctl(s->ep_fd, EPOLL_CTL_DEL, conn->fd, &ev);
    close(conn->fd);
    conn->prev->next = conn->next;
    if (conn->next)
        conn->next->prev = conn->prev;
    OPENSSL_free(conn->peer_addr);
    OPENSSL_free(conn);

    return -1;
}

int main(int argc, char *argv[])
{
    int opt = 0, port = -1;
    const char *addr = "127.0.0.1";
    char servaddr[SOCKADDR_LEN] = {0};
    server_t *server;

    CRYPTO_malloc_debug_init();
    MemCheck_start();

    g_err_bio = BIO_new_fp(stderr, 0);
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

    signal(SIGINT, sig_int);
    signal(SIGTERM, sig_int);

    if ((server = server_init(servaddr)) < 0)
    {
        BIO_printf(g_err_bio, "init server failed\n");
        exit(1);
    }
    server_loop(server);
    server_exit(server);

    BIO_free(g_err_bio);
    CRYPTO_mem_leaks_fp(stderr);
    exit(0);
}
