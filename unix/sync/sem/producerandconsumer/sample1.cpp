// 单生产者-单消费者
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

#define N 16

int gItems = 0;
struct
{
	int buff[N];
	sem_t nEmpty, nStored, mutex;
} gShared;

void* producer(void *arg);
void* consumer(void *arg);

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		errQuit("please assign items!", false);
	}

	gItems = atoi(argv[1]);
	for (int i = 0; i < N; ++i)
	{
		gShared.buff[i] = -1;
	}

	sem_init(&gShared.nEmpty, 0, N);
	sem_init(&gShared.nStored, 0, 0);
	sem_init(&gShared.mutex, 0, 1);

	pthread_t tidP;
	pthread_t tidC;
	pthread_create(&tidP, NULL, producer, NULL);
	pthread_create(&tidC, NULL, consumer, NULL);

	pthread_join(tidP, NULL);
	pthread_join(tidC, NULL);

	sem_destroy(&gShared.nEmpty);
	sem_destroy(&gShared.nStored);
	sem_destroy(&gShared.mutex);
	exit(0);
}

void* producer(void *arg)
{
	for (int i = 0; i < gItems; ++i)
	{
		sem_wait(&gShared.nEmpty);
		// sem_wait(&gShared.mutex);

		gShared.buff[i % N] = i;

		// sem_post(&gShared.mutex);
		sem_post(&gShared.nStored);
	}
	return NULL;
}

void* consumer(void *arg)
{
	for (int i = 0; i < gItems; ++i)
	{
		sem_wait(&gShared.nStored);
		// sem_wait(&gShared.mutex);

		if (gShared.buff[i % N] != i)
		{
			printf("error! %dth item access conflict, index=%d, curval=%d!\n", i, i%N, gShared.buff[i % N]);
		}

		// sem_post(&gShared.mutex);
		sem_post(&gShared.nEmpty);
	}
	return NULL;
}
