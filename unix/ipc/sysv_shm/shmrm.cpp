#include "shmdef.h"
#include "common/common.h"

int main(int argc, char *argv[])
{
	key_t key = ftok(SHM_PATH, MY_SHM_ID);
	if (key < 0)
		errQuit("ftok err");

	int shmid = shmget(key, 0, 0);
	if (shmid < 0)
		errQuit("get shm failed.");

	if (shmctl(shmid, IPC_RMID, NULL) < 0)
		errQuit("rm shm failed.");

	printf("rm shm ok!\n");
	exit(0);
}
