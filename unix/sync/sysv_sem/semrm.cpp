#include "semdef.h"

int main(int argc, char *argv[])
{
	key_t key = ftok(SEM_PATH, 1);
	if (key < 0)
		errQuit();

	int semid = semget(key, 0, 0);
	if (semid < 0)
		errQuit();

	if (semctl(semid, 0, IPC_RMID) == 0)
		printf("rm ok.\n");
	
	exit(0);
}
