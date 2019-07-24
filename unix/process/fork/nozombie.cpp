
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	int pid = -1;
	if ((pid = fork()) < 0)
	{
		printf("fork error.\n");
		abort();
	}
	else if(pid == 0)
	{
		if ((pid = fork()) < 0)
		{
			printf("fork error.\n");
		}
		else if(pid > 0)
			exit(0);

		sleep(2);
		printf("child process. pid=%d  ppid=%d\n", getpid(), getppid());
		exit(0);
	}

	printf("parent process. pid=%d\n", getpid());

	exit(0);
}
