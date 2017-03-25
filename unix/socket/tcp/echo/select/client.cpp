
#include <unistd.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SA struct sockaddr

static void errsys(const char *msg, int nErr);

int main(int argc, char *argv[]) {
	if (argc < 2) {
		errsys("enter your server ip!", 0);
	}
	
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		errsys("create sockfd err.", errno);
	}

	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(60000);

	if (connect(sockfd, (const SA *)&servaddr, sizeof(servaddr)) < 0) {
		errsys("connect err.", errno);
	}

	fd_set allset, rset;
	FD_ZERO(&allset);
	FD_SET(fileno(stdin), &allset);
	FD_SET(sockfd, &allset);
	
	int maxfd = fileno(stdin);
	if (sockfd > maxfd) {
		maxfd = sockfd;
	}

	static const int s_buffSize = 256;
	char buff[s_buffSize] = {0};
	bool bEof = false;
	for (;;) {
		rset = allset;

		struct timeval limTim;
		limTim.tv_sec = 5;
		limTim.tv_usec = 0;
		int nReady = select(maxfd+1, &rset, NULL, NULL, &limTim);

		if (0 == nReady) {	// timeout
			if (bEof) {
				printf("this situation should't hanppen. the server fucks me?");
				break;
			}
			else {
				printf("tik tok!\n");
				continue;
			}
		}
		
		if (FD_ISSET(fileno(stdin), &rset)) {  // 从标准输入读入数据
			int n = read(fileno(stdin), buff, s_buffSize);
			if (n > 0) {
				if (write(sockfd, buff, n) != n) {
					printf("send data err.\n");
					exit(2);
				}
			}
			else {
				bEof = true;
				shutdown(sockfd, SHUT_WR);
			}
			--nReady;
		}

		if (nReady > 0 && FD_ISSET(sockfd, &rset)) {  // 收到服务器回写数据
			int n = read(sockfd, buff, s_buffSize);
			if (n > 0) {
				write(fileno(stdout), buff, n);
			}
			else if (n < 0) {
				errsys("server quit.\n", errno);
			}
			else {
				if (bEof) {
					printf("echo finished.\n");
				}
				else {
					printf("server shutdown.\n");
				}
				break;
			}
			--nReady;
		}
	}
	
	exit(0);
}

static void errsys(const char *msg, int nErr) {
	const char *s_err = "";
	if (nErr != 0) {
		s_err = strerror(nErr);
	}
	printf("%s %s\n", msg, s_err);
	exit(1);
}
