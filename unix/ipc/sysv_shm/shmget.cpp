#include "shmdef.h"
#include "common/common.h"

int main(int argc, char *argv[])
{
	int size = SHM_SIZE;
	if (argc > 1)
		size = atoi(argv[1]);

	key_t key = ftok(SHM_PATH, MY_SHM_ID);
	if (key < 0)
		errQuit("ftok err.");

	if (shmget(key, size, IPC_CREAT|IPC_EXCL|0644) < 0)
		errQuit("create shm failed.");

	printf("create shm success.\n");
	exit(0);
}
