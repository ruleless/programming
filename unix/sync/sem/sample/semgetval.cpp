#include "semdef.h"

int main(int argc, char *argv[])
{
	sem_t *s = sem_open(SEM_NAME, 0);
	if (s == SEM_FAILED)
		errQuit("open sem failed.");

	int semval = 0;
	sem_getvalue(s, &semval);
	printf("semval=%d\n", semval);

	sem_close(s);
	
	exit(0);
}
