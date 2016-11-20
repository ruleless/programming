
#include <unistd.h>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SA struct sockaddr

static void errsys(const char *msg);

int main(int argc, char *argv[]) {
	static const int s_errBuffSize = 256;
	char errBuff[s_errBuffSize] = {0};
	if (argc < 2) {
		errsys("no input param!");
	}

	int cliFD = -1;
	if ((cliFD = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		errsys("create socket err!");
	}

	struct sockaddr_in servaddr;
	servaddr.sin_family = AF_INET;
	if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
		errsys("illegal ip addr!");
	}
	servaddr.sin_port = htons(60000);

	if (connect(cliFD, (const SA *)&servaddr, sizeof(servaddr)) < 0) {
		snprintf(errBuff, s_errBuffSize, "connect err! %s", strerror(errno));
		errsys(errBuff);
	}

	static const int s_buffSize = 1024;
	char buff[s_buffSize];
	while (fgets(buff, s_buffSize, stdin) != NULL) {
		int n = strlen(buff);
		if (write(cliFD, buff, n) != n) {
			errsys("write err!");
		}

		if ((n = read(cliFD, buff, s_buffSize)) < 0) {
			errsys("read err!");
		}
		else if (n > 0) {
			write(STDOUT_FILENO, buff, n);
		}
		else {
			snprintf(buff, s_buffSize, "server shutdown!");
			write(STDOUT_FILENO, buff, strlen(buff));
			break;
		}
	}

	exit(0);
}

static void errsys(const char *errmsg) {
	printf("%s\n", errmsg);
	exit(1);
}
