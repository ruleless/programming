#include "common.h"

int main(int argc, char *argv[])
{
	if (mkfifo(FIFO_PATH, 0644) < 0 && errno != EEXIST)
		errQuit();

	int servFd = open(FIFO_PATH, O_RDONLY);
	if (servFd < 0)
		errQuit();

	int dummyfd = open(FIFO_PATH, O_WRONLY);
	if (dummyfd < 0)
		errQuit();

	char buf[11] = {0};
	int n = 0;
	memset(buf, 0, sizeof(buf));
	while ((n = read(servFd, buf, 10)) > 0)
	{
		if (n != 10)
		{
			printf("client write len illegal len = %d\n", n);
			continue;
		}

		int clientpid = atoi(buf);
		if (clientpid > 0)
		{
			if (fork() == 0)
			{
				char echoRPath[MAX_BUF];
				char echoWPath[MAX_BUF];
				snprintf(echoRPath, MAX_BUF, "%s%dw", FIFO_ECHO, clientpid);
				snprintf(echoWPath, MAX_BUF, "%s%dr", FIFO_ECHO, clientpid);

				int writeFd = open(echoWPath, O_WRONLY);
				if (writeFd < 0)
					errQuit();
				write(writeFd, "ok", 2);
				
				int readFd = open(echoRPath, O_RDONLY);
				if (readFd < 0)
					errQuit();				

				char echoBuf[MAX_BUF];
				int n = 0;
				while((n = read(readFd, echoBuf, MAX_BUF)) > 0)
				{
					write(writeFd, echoBuf, n);
				}

				printf("client %u stoped.\n");
				
				exit(0);
			}
		}
	}
	
	exit(0);
}
