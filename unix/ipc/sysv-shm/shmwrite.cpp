#include "shmdef.h"
#include "common/common.h"

#define BUFF_SIZE 512

int main(int argc, char *argv[])
{
	key_t key = ftok(SHM_PATH, MY_SHM_ID);
	if (key < 0)
		errQuit("ftok err.");

	int shmid = shmget(key, 0, 0);
	if (shmid < 0)
		errQuit("open shm failed.");

	char *ptr = (char *)shmat(shmid, NULL, 0);
	if (ptr < 0)
		errQuit("attach shm err.");

	struct shmid_ds shmds;
	if (shmctl(shmid, IPC_STAT, &shmds) < 0)
		errQuit("get shm stat err.");

	int shmSize = shmds.shm_segsz;
	int cur = 0;
	char buff[BUFF_SIZE];
	int n = 0;
	while ((n = read(STDIN_FILENO, buff, BUFF_SIZE)) > 0)
	{
		int cpLen = min(n, shmSize-cur);
		if (cpLen > 0)
		{
			memcpy(ptr+cur, buff, cpLen);
			cur += cpLen;

			if (cur >= shmSize)
				break;
		}
		else
		{
			break;
		}
	}
	exit(0);
}
