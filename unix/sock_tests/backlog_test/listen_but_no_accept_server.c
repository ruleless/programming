// listen but no accept

#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>

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

    char line[128];
    while (fgets(line, sizeof(line), stdin)) {
        if (strncmp(line, "quit", 4) == 0) {
            fprintf(stdout, "Bye!\n");
            exit(0);
        }
    }

    exit(0);
}
