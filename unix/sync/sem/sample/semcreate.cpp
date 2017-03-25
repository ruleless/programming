#include "semdef.h"

int main(int argc, char *argv[])
{
	int semval = 1;
	if (argc > 1)
	{
		semval = atoi(argv[1]);
	}

	if (sem_open(SEM_NAME, O_RDWR|O_CREAT|O_EXCL, 0664, semval) == SEM_FAILED)
	{
		errQuit("open sem failed.");
	}

	printf("create sem %s ok!\n", SEM_NAME);
	exit(0);
}
