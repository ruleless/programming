#include <pthread.h>
#include <sys/mman.h>
#include "shmdef.h"
#include "common.h"

int main(int argc, char *argv[])
{
	// 打开共享内存区
	int shmFd = shm_open(SHM_NAME, O_RDWR, 0);
	if (shmFd < 0)
	{
		errQuit("open shm failed.");
	}
	Shared *ptr = (Shared *)mmap(NULL, sizeof(Shared), PROT_READ|PROT_WRITE, MAP_SHARED, shmFd, 0);
	if (MAP_FAILED == ptr)
	{
		errQuit("mmap failed.", false);
	}
	close(shmFd);

	// 生产
	char buff[MSGSize] = {0};
	while (fgets(buff, MSGSize, stdin))
	{
		if (-1 == sem_wait(&ptr->nEmpty))
		{
			sem_wait(&ptr->overflowMutex);
			++ptr->nOverflow;
			sem_post(&ptr->overflowMutex);
			continue;
		}

		sem_wait(&ptr->mutex);

		int n = strlen(buff);
		if (n > 0 && buff[n-1] == '\n')
			buff[n-1] = 0;
		snprintf(ptr->msg[ptr->put], MSGSize, "client %d say(bufidx=%d): %s", (int)getpid(), ptr->put, buff);
		ptr->put = (ptr->put + 1) % QSize;

		sem_post(&ptr->mutex);
		sem_post(&ptr->nStored);
	}
	
	exit(0);
}
