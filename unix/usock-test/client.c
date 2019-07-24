#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <sys/un.h>
#include <sys/socket.h>

#define TEST_MSG "test unix socket"
#define TEST_MSG_LEN sizeof(TEST_MSG)

int main(int argc, char *argv[])
{
    int fd = 0;
    int r;
    int sendbuf = 0;
    socklen_t optlen = 0;
    unsigned n = 1;
    struct sockaddr_un servaddr;
    char sendmsg[716] = {"hello world"};

    if (argv[1])
    {
        n = atoi(argv[1]);
    }

	if ((fd = socket(AF_UNIX, SOCK_DGRAM, 0)) < 0)
	{
		return -1;
	}

    // sendbuf = 1024*1024;
    // optlen = sizeof(sendbuf);
    // setsockopt(fd, SOL_SOCKET, SO_SNDBUF, &sendbuf, optlen);

    servaddr.sun_family = AF_UNIX;
    snprintf(servaddr.sun_path, sizeof(servaddr.sun_path), "/tmp/UnixSock_Test");

    while (n--)
    {
        r = sendto(fd, sendmsg, sizeof(sendmsg), MSG_DONTWAIT, (const struct sockaddr *)&servaddr, sizeof(servaddr));
        // r = sendto(fd, sendmsg, sizeof(sendmsg), 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));
        optlen = sizeof(sendbuf);
        getsockopt(fd, SOL_SOCKET, SO_SNDBUF, &sendbuf, &optlen);

        if (r < 0)
        {
            fprintf(stderr, "send failed, sendbuf:%d %s\n", sendbuf, strerror(errno));
        }
        else
        {
            fprintf(stdout, "send ok, sendbuf:%d\n", sendbuf);
        }
    }

    exit(0);
}
