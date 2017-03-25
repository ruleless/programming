
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

static const int s_maxChildP = 10;

int main(int argc, char *argvp[])
{
	pid_t childPid = -1;
	if ((childPid = fork()) < 0)
	{
		printf("fork error!\n");
		abort();
	}
	else if (childPid == 0) // 子进程
	{
		execlp("./cat", "cat", NULL);
	}

	waitpid(childPid, NULL, 0);
	
	exit(0);
}
