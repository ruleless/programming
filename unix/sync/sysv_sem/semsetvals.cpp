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
	memset(semarr, 0, sizeof(unsigned short)*ds.sem_nsems);
	for (int i = 1; i < argc && i-1 < ds.sem_nsems; ++i)
		semarr[i-1] = atoi(argv[i]);

	arg.array = semarr;
	if (semctl(semid, 0, SETALL, arg) < 0)
		errQuit();
	
	exit(0);
}
