#include <pthread.h>
#include <sys/mman.h>
#include "common.h"
#include "shmdef.h"

int main(int argc, char *argv[])
{
	// 创建Posix共享内存区
	shm_unlink(SHM_NAME);
	int shmFd = shm_open(SHM_NAME, O_RDWR|O_CREAT|O_EXCL, 0664);
	if (shmFd < 0)
	{
		errQuit("create shm failed.");
	}
	ftruncate(shmFd, sizeof(Shared));
	Shared *ptr = (Shared *)mmap(NULL, sizeof(Shared), PROT_READ|PROT_WRITE, MAP_SHARED, shmFd, 0);
	if (MAP_FAILED == ptr)
	{
		errQuit("mmap failed.", false);
	}
	close(shmFd);

	// 初始化信号量
	sem_init(&ptr->nEmpty, 1, QSize);
	sem_init(&ptr->nStored, 1, 0);
	sem_init(&ptr->mutex, 1, 1);
	sem_init(&ptr->overflowMutex, 1, 1);

	// 消费
	int index = 0;
	int lastOverflow = 0;
	for (;;)
	{
		sem_wait(&ptr->nStored);
		printf("%s\n", ptr->msg[index]);
		index = (index + 1) % QSize;
		sem_post(&ptr->nEmpty);

		sem_wait(&ptr->overflowMutex);
		if (ptr->nOverflow != lastOverflow)
		{
			printf("overflow:%d\n", ptr->nOverflow);
			lastOverflow = ptr->nOverflow;
		}
		sem_post(&ptr->overflowMutex);
	}

	// 销毁信号量 
	sem_destroy(&ptr->nEmpty);
	sem_destroy(&ptr->nStored);
	sem_destroy(&ptr->mutex);
	
	exit(0);
}
