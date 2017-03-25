#include "semdef.h"

int main(int argc, char *argv[])
{
	sem_t *s = sem_open(SEM_NAME, 0);
	if (SEM_FAILED == s)
		errQuit("open sem failed.");

	sem_post(s);
	exit(0);
}
