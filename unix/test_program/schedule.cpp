#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		errQuit("too few args!", false);
	}

	int sec = atoi(argv[1]);
	sec = max(sec, 1);

	for (;;)
	{
		pid_t pid = -1;
		if ((pid = fork()) == 0)
		{
			execvp(argv[2], argv+2);
		}

		waitpid(pid, NULL, 0);

		sleep(sec);
	}

	exit(0);
}
