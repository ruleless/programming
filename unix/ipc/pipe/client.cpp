#include "common.h"

int main(int argc, char *argv[])
{
	char echoRPath[MAX_BUF];
	char echoWPath[MAX_BUF];
	snprintf(echoRPath, MAX_BUF, "%s%dr", FIFO_ECHO, (int)getpid());
	snprintf(echoWPath, MAX_BUF, "%s%dw", FIFO_ECHO, (int)getpid());

	if (mkfifo(echoRPath, 0644) < 0 && errno != EEXIST)
		errQuit();
	if (mkfifo(echoWPath, 0644) < 0 && errno != EEXIST)
		errQuit();

	int servFd = open(FIFO_PATH, O_WRONLY);
	if (servFd < 0)
		errQuit();

	char buf[MAX_BUF];
	snprintf(buf, MAX_BUF, "%10d", (int)getpid());
	write(servFd, buf, 10);

	int readFd = open(echoRPath, O_RDONLY);
	if (readFd < 0)
		errQuit();

	int n = read(readFd, buf, 2);
	if (n != 2 || buf[0] != 'o' || buf[1] != 'k')
		errQuit();

	int writeFd = open(echoWPath, O_WRONLY);
	if (writeFd < 0)
		errQuit();

	while (fgets(buf, MAX_BUF, stdin) != NULL)
	{
		int len = strlen(buf);
		write(writeFd, buf, len);
		
		n = read(readFd, buf, MAX_BUF-1);
		if (n > 0)
		{
			buf[n] = '\0';
			printf("server ret:%s", buf);
		}
	}
	
	exit(0);
}
