#include "semdef.h"

int main(int argc, char *argv[])
{
	key_t key = ftok(SEM_PATH, 1);
	if (key < 0)
		errQuit();

	int semnum = 1;
	if (argc > 1)
		semnum = atoi(argv[1]);

	if (semget(key, semnum, 0644|IPC_CREAT|IPC_EXCL) < 0)
		errQuit();

	printf("create sem ok!\n");
	
	exit(0);
}
