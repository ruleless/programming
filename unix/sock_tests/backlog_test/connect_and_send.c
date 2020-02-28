// connect and send

#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sockaddr SA;

static void err_quit(const char *msg, int nErr) {
	const char *s_err = strerror(nErr);
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
    int opt;

    const char *server_addr = NULL;
    int port = 60000;
    int try_times = 1024, send_bytes = 1024;
    char *sendbuf = NULL;

    while ((opt = getopt(argc, argv, "s:p:t:n:")) != -1) {
        switch (opt) {
        case 's':
            server_addr = optarg;
            break;
        case 'p':
            port = atoi(optarg);
            break;
        case 'n':
            send_bytes = atoi(optarg);
            break;
        case 't':
            try_times = atoi(optarg);
            break;
        default:
            break;
        }
    }

    sendbuf = (char *)malloc(send_bytes);
    memset(sendbuf, 'x', sizeof(sendbuf));

    if (!server_addr) {
        err_quit("no server address", 0);
    }

    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if (inet_pton(AF_INET, server_addr, &servaddr.sin_addr) <= 0) {
		err_quit("illegal server ip addr!", 0);
	}

    int i, n, cli_fd;
    int send_times = 0;
    for (i = 0; i < try_times; i++) {
        if ((cli_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            fprintf(stderr, "create socket failed, reason: ", strerror(errno));
            break;
        }

        fprintf(stdout, "connecting %s:%d\n", server_addr, port);
        if (connect(cli_fd, (const SA *)&servaddr, sizeof(servaddr)) < 0) {
            fprintf(stderr, "connect %s error, reason: %s\n", server_addr, strerror(errno));
            break;
        }

        fprintf(stdout, "%s:%d connected\n", server_addr, port);
        set_nonblocking(cli_fd);

        n = write(cli_fd, sendbuf, send_bytes);
        if (n < 0) {
            fprintf(stderr, "send error, reason: %s\n", strerror(n));
        } else if (n != send_bytes) {
            fprintf(stderr, "send %d bytes, %d less\n", n, send_bytes - n);
        }
        send_times++;
    }

    fprintf(stdout, "try %d times, input 'quit' to end this program!\n", send_times);

    char line[128];
    while (fgets(line, sizeof(line), stdin)) {
        if (strncmp(line, "quit", 4) == 0) {
            fprintf(stdout, "Bye!\n");
            exit(0);
        }
    }

    exit(0);
}
