#include "semdef.h"

int main(int argc, char *argv[])
{
	key_t key = ftok(SEM_PATH, 1);
	if (key < 0)
		errQuit();

	int semid = semget(key, 0, 0);
	if (semid < 0)
		errQuit();

	struct semid_ds ds;
	union semun arg;
	arg.buf = &ds;
	if (semctl(semid, 0, IPC_STAT, arg) < 0)
		errQuit();

	unsigned short *semarr = new unsigned short[ds.sem_nsems];
	arg.array = semarr;
	if (semctl(semid, 0, GETALL, arg) < 0)
		errQuit();

	for (int i = 0; i < ds.sem_nsems; ++i)
		printf("sem %d: %d\n", i, semarr[i]);

	exit(0);
}
