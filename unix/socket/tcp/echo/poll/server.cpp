
#include <unistd.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/time.h>
#include <poll.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FD_SIZE 2
#define SA struct sockaddr

static void errsys(const char *msg, int nErr);

int main(int argc, char *argv[]) {
	int listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if (listenfd < 0) {
		errsys("create listen socket failed.", errno);
	}

	struct sockaddr_in servaddr;
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(60000);

	if (bind(listenfd, (const SA *)&servaddr, sizeof(servaddr)) < 0) {
		errsys("bind addr err.", errno);
	}

	if (listen(listenfd, 5) < 0) {
		errsys("listen failed.", errno);
	}

	struct pollfd fdArray[FD_SIZE];
	for (int i = 0; i < FD_SIZE; ++i) {
		fdArray[i].fd = -1;
		fdArray[i].events = 0;
		fdArray[i].revents = 0;
	}

	fdArray[0].fd = listenfd;
	fdArray[0].events = POLLRDNORM;
	int maxi = 0;

	static const int s_buffSize = 256;
	char s_recvBuff[s_buffSize];

	for (;;) {
		int nReady = poll(fdArray, maxi+1, -1);

		// 有新客户端连入
		if (fdArray[0].revents & POLLRDNORM) {
			int connfd = accept(fdArray[0].fd, NULL, NULL);
			if (connfd < 0) {
				errsys("accept err!", errno);
			}

			int i = 1;
			for (; i < FD_SIZE; ++i) {
				if (fdArray[i].fd < 0) {
					fdArray[i].fd = connfd;
					fdArray[i].events = POLLRDNORM;
					fdArray[i].revents = 0;

					if (i > maxi) {
						maxi = i;
					}
					break;
				}
			}
			if (i == FD_SIZE) {
				close(connfd);
				printf("too many clients\n");
			}

			if (--nReady <= 0) {
				continue;
			}
		}

		// 处理客户请求
		for (int i = 1; i <= maxi; ++i) {
			if (fdArray[i].fd < 0) {
				continue;
			}

			if (fdArray[i].revents & (POLLRDNORM | POLLERR)) {
				int n = read(fdArray[i].fd, s_recvBuff, s_buffSize);
				if (n > 0) {
					int writen = write(fdArray[i].fd, s_recvBuff, n);
					if (writen != n) {
						printf("write client socket %d err. write len:%d\n", fdArray[i].fd, writen);
					}
				}
				else {	// 读入FIN或除错均关闭连接
					close(fdArray[i].fd);
					fdArray[i].fd = -1;
					fdArray[i].events = 0;
					fdArray[i].revents = 0;
					if (i == maxi) {
						--maxi;
						break;
					}
				}

				if (--nReady <= 0) {
					break;
				}
			}
		}
	}
}

static void errsys(const char *msg, int nErr) {
	const char *s_err = strerror(nErr);
	if (NULL == s_err) {
		s_err = "";
	}
	printf("%s %s\n", msg, s_err);
	exit(1);
}
