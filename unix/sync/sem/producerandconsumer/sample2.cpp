// 多生产者-单消费者模型
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

#define N 16
#define MAX_THREAD 16

struct Shared
{
	int buff[N];
	int nput;
	int nputval;

	sem_t nEmpty, nStored, mutex;

	Shared()
	{
		memset(buff, -1, sizeof(buff));
		nput = 0;
		nputval = 0;
	}
};

static int gItems = N;
static Shared gShared;

void* producer(void *arg);
void* consumer(void *arg);

int main(int argc, char *argv[])
{
	if (argc > 1)
		gItems = atoi(argv[1]);
	int nProducer = MAX_THREAD;
	if (argc > 2)
		nProducer = min(nProducer, atoi(argv[2]));

	// 初始化信号量
	sem_init(&gShared.nEmpty, 0, N);
	sem_init(&gShared.nStored, 0, 0);
	sem_init(&gShared.mutex, 0, 1);

	// 创建生产者和消费者线程
	pthread_t tidProducer[MAX_THREAD];
	int execTimesOfProducer[MAX_THREAD];
	memset(execTimesOfProducer, 0, sizeof(execTimesOfProducer));
	for (int i = 0; i < nProducer; ++i)
	{
		pthread_create(&tidProducer[i], NULL, producer, &execTimesOfProducer[i]);
	}

	pthread_t tidConsumer;
	pthread_create(&tidConsumer, NULL, consumer, NULL);

	// 等待线程结束
	for (int i = 0; i < nProducer; ++i)
	{
		pthread_join(tidProducer[i], NULL);
	}
	pthread_join(tidConsumer, NULL);

	int totalExecTimes = 0;
	for (int i = 0; i < nProducer; ++i)
	{
		totalExecTimes += execTimesOfProducer[i];
		printf("thread %d exec %d times\n", i, execTimesOfProducer[i]);
	}
	PRINT_INTVAL(totalExecTimes);

	// 销毁信号量
	sem_destroy(&gShared.nEmpty);
	sem_destroy(&gShared.nStored);
	sem_destroy(&gShared.mutex);

	exit(0);
}

void* producer(void *arg)
{
	for (;;)
	{
		sem_wait(&gShared.nEmpty);
		sem_wait(&gShared.mutex);

		if (gShared.nputval >= gItems)
		{
			sem_post(&gShared.nEmpty);
			sem_post(&gShared.mutex);
			return NULL;
		}

		gShared.buff[gShared.nput++%N] = gShared.nputval++;
		(*(int *)arg)++;

		sem_post(&gShared.mutex);
		sem_post(&gShared.nStored);
	}

	return NULL;
}

void* consumer(void *arg)
{
	for (int i = 0; i < gItems; ++i)
	{
		sem_wait(&gShared.nStored);
		if (gShared.buff[i%N] != i)
		{
			printf("conflict! index=%d  val=%d  legal val=%d\n", i%N, gShared.buff[i%N], i);
		}
		sem_post(&gShared.nEmpty);
	}

	return NULL;
}
