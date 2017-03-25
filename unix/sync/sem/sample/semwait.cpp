#include "semdef.h"

void sigInt(int signo)
{
	printf("got SIGINT\n");
	exit(1);
}

int main(int argc, char *argv[])
{
	sem_t *s = sem_open(SEM_NAME, 0);
	if (s == SEM_FAILED)
		errQuit("open sem failed.");

	struct sigaction newAct, oldAct;
	newAct.sa_handler = sigInt;
	sigemptyset(&newAct.sa_mask);
	newAct.sa_flags = 0;

	if (sigaction(SIGINT, &newAct, &newAct) != 0)
	{
		errQuit("setup sigint failed.");
	}
	
	if (-1 == sem_wait(s))
		errQuit("sem wait failed.");
	printf("P\n");

	sigaction(SIGINT, &oldAct, NULL);
	
	sem_close(s);
	exit(0);
}
