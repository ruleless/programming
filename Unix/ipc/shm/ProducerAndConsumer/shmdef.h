#ifndef __SHMDEF_H__
#define __SHMDEF_H__

#include <unistd.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QSize 1
#define MSGSize 256

#define SHM_NAME "shmecho"

struct Shared
{
	char msg[QSize][MSGSize];
	int put;
	sem_t nEmpty;
	sem_t nStored;
	sem_t mutex;

	int nOverflow;
	sem_t overflowMutex;

	Shared()
	{
		memset(msg, 0, sizeof(msg));
		put = 0;
		nOverflow = 0;
	}
};

#endif
