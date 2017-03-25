#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

#define N 256
static char s_buff[N];

int main(int argc, char *argv[])
{
	int res = regReadRecLock(STDIN_FILENO, 0, SEEK_SET, 0);
	if (res < 0)
		errQuit("reg read lock failed.");
	res = regWriteRecLock(STDOUT_FILENO, 0, SEEK_SET, 0);
	if (res < 0)
		errQuit("reg write lock failed.");
	int n = 0;
	while ((n = read(STDIN_FILENO, s_buff, N)) > 0)
	{
		if (n != write(STDOUT_FILENO, s_buff, n))
		{
			errQuit("write err.");
		}
	}
	exit(0);
}
