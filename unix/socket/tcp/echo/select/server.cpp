
#include "unp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SA struct sockaddr
#define FD_SIZE 2

static void errsys(const char *msg, int nErr);

int main(int argc, char *argv[]) {
	int listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if (listenfd < 0) {
		errsys("create listen fd err!", errno);
	}

	struct sockaddr_in servaddr;
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(60000);

	if (bind(listenfd, (const SA*)&servaddr, sizeof(servaddr)) < 0) {
		errsys("bind err!", errno);
	}

	if (listen(listenfd, 5) < 0) {
		errsys("listen err!", errno);
	}

	int maxfd = listenfd;
	fd_set allset, readset;
	FD_ZERO(&allset);
	FD_SET(listenfd, &allset);
	FD_ZERO(&readset);

	int connfds[FD_SIZE];
	memset(connfds, -1, sizeof(connfds));

	static const int s_buffSize = 256;
	char s_recvBuff[s_buffSize];

	for (;;) {
		readset = allset;
		int nready = select(maxfd+1, &readset, NULL, NULL, NULL);
		if (nready < 0){
			errsys("select err!", errno);
		}

		if (FD_ISSET(listenfd, &readset)) {	 // 有新客户连入服务器
			int fd = accept(listenfd, NULL, NULL);
			printf("new clients! fd:%d\n", fd);
			if (fd >= 0) {
				int i = 0;
				for (; i < FD_SIZE; ++i) {
					if (connfds[i] < 0) {
						connfds[i] = fd;
						FD_SET(fd, &allset);
						if (fd > maxfd) {
							maxfd = fd;
						}
						break;
					}
				}
				if (i == FD_SIZE) {
					printf("too many clients!\n");
					close(fd);
				}
			}

			if (--nready <= 0) {
				continue;
			}
		}

		// 处理连接套接字
		for (int i = 0; i < FD_SIZE; ++i) {
			int fd = connfds[i];
			if (fd >= 0 && FD_ISSET(fd, &readset)) {
				int n = read(fd, s_recvBuff, s_buffSize);
				if (n == 0) {  // 客户端发送FIN
					connfds[i] = -1;
					FD_CLR(fd, &allset);
					if (maxfd == fd) {
						--maxfd;
					}
				}
				else if (n > 0) {  // 回写
					int writen = write(fd, s_recvBuff, n);
					if (writen != n) {
						printf("write sockfd %d err!write len:%d\n", fd, writen);
					}
				}
				else {	// 此情况不应出现
					errsys("read err!", errno);
				}

				if (--nready <= 0)
					break;
			}
		}
	}

	exit(0);
}

static void errsys(const char *msg, int nErr) {
	const char *s_err = strerror(nErr);
	if (NULL == s_err) {
		s_err = "";
	}
	printf("%s %s\n", msg, s_err);
	exit(1);
}
