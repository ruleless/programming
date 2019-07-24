#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>

#define OPT_ITEM(lv, name, func)                \
    {#name, lv, name, func}

union val
{
    int i_val;
    int l_val;
    struct linger  linger_val;
    struct timeval tm_val;
};

static char *sock_str_flag(union val *v, int l);
static char *sock_str_int(union val *v, int l);
static char *sock_str_linger(union val *v, int l);
static char *sock_str_timeval(union val *v, int l);

struct sock_opts
{
    const char *opt_str;
    int opt_level;
    int opt_name;
    char *(*get_opt_val)(union val *v, int l);
} sock_opts[] = {
    OPT_ITEM(SOL_SOCKET, SO_DEBUG, sock_str_flag),
    OPT_ITEM(SOL_SOCKET, SO_REUSEADDR, sock_str_flag),
    OPT_ITEM(SOL_SOCKET, SO_TYPE, sock_str_int),
    OPT_ITEM(SOL_SOCKET, SO_ERROR, sock_str_int),
    OPT_ITEM(SOL_SOCKET, SO_DONTROUTE, sock_str_flag),
    OPT_ITEM(SOL_SOCKET, SO_BROADCAST, sock_str_flag),
    OPT_ITEM(SOL_SOCKET, SO_SNDBUF, sock_str_int),
    OPT_ITEM(SOL_SOCKET, SO_RCVBUF, sock_str_int),
    OPT_ITEM(SOL_SOCKET, SO_SNDBUFFORCE, sock_str_int),
    OPT_ITEM(SOL_SOCKET, SO_RCVBUFFORCE, sock_str_int),
    OPT_ITEM(SOL_SOCKET, SO_KEEPALIVE, sock_str_flag),
    OPT_ITEM(SOL_SOCKET, SO_OOBINLINE, sock_str_flag),
    OPT_ITEM(SOL_SOCKET, SO_NO_CHECK, sock_str_flag),
    OPT_ITEM(SOL_SOCKET, SO_PRIORITY, sock_str_int),
    // OPT_ITEM(SOL_SOCKET, SO_LINGER, sock_str_linger),
    // OPT_ITEM(SOL_SOCKET, SO_BSDCOMPAT, ),
    OPT_ITEM(SOL_SOCKET, SO_REUSEPORT, sock_str_flag),

    {NULL, 0, 0, NULL},
};

static char *sock_str_flag(union val *v, int l)
{
    static char RES[16];

    do
    {
        if (l != sizeof(v->i_val))
        {
            snprintf(RES, sizeof(RES), "invalid return");
            break;
        }
        if (v->i_val)
        {
            snprintf(RES, sizeof(RES), "on");
            break;
        }

        snprintf(RES, sizeof(RES), "off");
    } while (0);

    return RES;
}

static char *sock_str_int(union val *v, int l)
{
    static char RES[16];

    do
    {
        if (l != sizeof(v->i_val))
        {
            snprintf(RES, sizeof(RES), "invalid return");
            break;
        }

        snprintf(RES, sizeof(RES), "%d", v->i_val);
    } while (0);

    return RES;
}

static char *sock_str_linger(union val *v, int l)
{}

static char *sock_str_timeval(union val *v, int l)
{}

int main(int argc, char *argv[])
{
    struct sock_opts *opts;
    int fd;
    union val v;
    socklen_t l;

    for (opts = sock_opts; opts->opt_str; opts++)
    {
        fd = socket(AF_INET, SOCK_STREAM, 0);
        if (fd < 0)
            continue;

        printf("%-15s: ", opts->opt_str);

        l = sizeof(v);
        if (getsockopt(fd, opts->opt_level, opts->opt_name, &v, &l) < 0)
        {
            printf("get sockopt err, reason:%s", strerror(errno));
            goto new_line;
        }

        printf("default=%s", (*opts->get_opt_val)(&v, l));

  new_line:
        putchar('\n');
    }

    exit(0);
}
