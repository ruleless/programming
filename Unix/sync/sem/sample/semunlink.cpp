#include "semdef.h"

int main(int argc, char *argv[])
{
	if (sem_unlink(SEM_NAME) == -1)
		errQuit("delete failed!");
	printf("delete sem %s ok!\n", SEM_NAME);
	exit(0);
}
