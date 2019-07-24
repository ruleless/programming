#include "shmdef.h"
#include "common/common.h"

int main(int argc, char *argv[])
{
	key_t key = ftok(SHM_PATH, MY_SHM_ID);
	if (key < 0)
		errQuit("ftok err.");

	int shmid = shmget(key, 0, 0);
	if (shmid < 0)
		errQuit("open shm err.");

	void *ptr = shmat(shmid, NULL, 0);
	if (ptr < 0)
		errQuit("attach shm err.");

	struct shmid_ds shmds;
	shmctl(shmid, IPC_STAT, &shmds);
	write(STDOUT_FILENO, ptr, shmds.shm_segsz);

	exit(0);
}

