
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SA struct sockaddr

static void errsys(const char *errmsg);
static void sigChild(int signo);
static void echoClient(int connfd, const SA *cliaddr, uint32_t addrlen);

int main(int argc, char *argv[])
{
	int listenfd = -1;
	if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		errsys("create listen sock err!");
	}

	struct sockaddr_in servaddr;
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	servaddr.sin_port = htons(60000);
	if (bind(listenfd, (SA*)&servaddr, sizeof(servaddr)) < 0) {
		errsys("bind addr err!");
	}

	if (listen(listenfd, 5) < 0) {
		errsys("listen failed!");
	}

	struct sigaction newact, oldact;
	newact.sa_handler = sigChild;
	sigemptyset(&newact.sa_mask);
	newact.sa_flags = SA_INTERRUPT;
	if (sigaction(SIGCHLD, &newact, &oldact) < 0) {
		errsys("setup signal failed!");
	}

	for (;;) {
		int connfd = -1;
		struct sockaddr_in cliaddr;
		uint32_t addrLen = sizeof(cliaddr);

		if ((connfd = accept(listenfd, (SA *)&cliaddr, &addrLen)) < 0) {
			if (errno == EINTR) {
				continue;
			}
			else {
				errsys("accept err!");
			}
		}
		else {
			int pid = -1;
			if ((pid = fork()) < 0) {
				errsys("fork err!");
			}
			else if (pid == 0) {
				close(listenfd);
				echoClient(connfd, (const SA *)&cliaddr, addrLen);
				exit(0);
			}

			close(connfd);
		}
	}
	exit(0);
}

static void errsys(const char *errmsg) {
	printf("%s\n", errmsg);
	exit(1);
}

static void sigChild(int signo) {
	int status = 0;
	int pid = wait(&status);

	static const int s_buffSize = 255;
	char hintBuff[s_buffSize];
	snprintf(hintBuff, s_buffSize-1, "child process %d exit status:%d\n", pid, status);
	write(STDIN_FILENO, hintBuff, strlen(hintBuff));
}

static void echoClient(int connfd, const SA *cliaddr, uint32_t addrlen) {
	static const int s_buffSize = 1024;
	char buff[s_buffSize] = {0};

	for (;;) {
		int n = 0;
		if ((n = read(connfd, buff, s_buffSize)) < 0) {
			if (errno == EINTR) {
				continue;
			}
			else {
				errsys("server read err!");
			}
		}
		else if (n > 0) {
			if (write(connfd, buff, n) != n) {
				errsys("write err!");
			}
		}
		else {
			close(connfd);
			break;
		}
	}
}
