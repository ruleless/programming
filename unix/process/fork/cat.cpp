
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

static const int s_buffSize = 8;
char buff[s_buffSize];

int main(int argc, char* argv[])
{
	int n = 0;
	while ((n=read(STDIN_FILENO, buff, s_buffSize)) > 0)
	{
		if (write(STDOUT_FILENO, buff, n) != n)
		{
			printf("write error! pid=%d\n", getpid());
			exit(1);
		}
	}
	exit(0);
}
