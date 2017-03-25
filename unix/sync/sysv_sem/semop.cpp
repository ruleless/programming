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
	if (semctl(semid, 0, SEM_STAT, arg) < 0)
		errQuit();

	static const int N = 10;
	struct sembuf opBufs[N];
	int n = 0;
	for (int i = 1; i < argc; ++i)
	{
		opBufs[n].sem_op = atoi(argv[i]);
		opBufs[n].sem_num = i-1;
		opBufs[n].sem_flg = 0;
		++n;
	}
	if (semop(semid, opBufs, n) < 0)
		errQuit();
	
	exit(0);
}
