// 多生产者-多消费者模型
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
	int nget;
	int ngetval;

	sem_t nEmpty, nStored, producerMutex, consumerMutex;

	Shared()
	{
		memset(buff, -1, sizeof(buff));
		nput = nputval = 0;
		nget = ngetval = 0;
	}
};

int gItems = 0;
Shared gShared;

void* producer(void *arg);
void* consumer(void *arg);

int main(int argc, char *argv[])
{
	int nProducer = MAX_THREAD;
	int nConsumer = MAX_THREAD;
	gItems = N;

	// 参数设置
	if (argc > 1)
		gItems = atoi(argv[1]);
	if (argc > 2)
		nProducer = atoi(argv[2]);
	if (argc > 3)
		nConsumer = atoi(argv[3]);
	nProducer = min(nProducer, MAX_THREAD);
	nConsumer = min(nConsumer, MAX_THREAD);

	// 信号量初始化
	sem_init(&gShared.nEmpty, 0, N);
	sem_init(&gShared.nStored, 0, 0);
	sem_init(&gShared.producerMutex, 0, 1);
	sem_init(&gShared.consumerMutex, 0, 1);

	// 创建生产者线程
	pthread_t tidProducer[MAX_THREAD];
	int execTimesOfProducer[MAX_THREAD];
	memset(execTimesOfProducer, 0, sizeof(execTimesOfProducer));
	for (int i = 0; i < nProducer; ++i)
	{
		pthread_create(&tidProducer[i], NULL, producer, &execTimesOfProducer[i]);
	}

	// 创建消费者线程
	pthread_t tidConsumer[MAX_THREAD];
	int execTimesOfConsumer[MAX_THREAD];
	memset(execTimesOfConsumer, 0, sizeof(execTimesOfConsumer));
	for (int i = 0; i < nConsumer; ++i)
	{
		pthread_create(&tidConsumer[i], NULL, consumer, &execTimesOfConsumer[i]);
	}

	// 等待线程终止
	for (int i = 0; i < nProducer; ++i)
	{
		pthread_join(tidProducer[i], NULL);
	}
	for (int i = 0; i < nConsumer; ++i)
	{
		pthread_join(tidConsumer[i], NULL);
	}

	// 信号量销毁
	sem_destroy(&gShared.nEmpty);
	sem_destroy(&gShared.nStored);
	sem_destroy(&gShared.producerMutex);
	sem_destroy(&gShared.consumerMutex);

	for (int i = 0; i < nProducer; ++i)
	{
		printf("producer %d run %d times.\n", i, execTimesOfProducer[i]);
	}
	for (int i = 0; i < nConsumer; ++i)
	{
		printf("consumr %d run %d times.\n", i, execTimesOfConsumer[i]);
	}

	exit(0);
}

void* producer(void *arg)
{
	for(;;)
	{
		sem_wait(&gShared.nEmpty);
		sem_wait(&gShared.producerMutex);

		if (gShared.nputval >= gItems)
		{
			sem_post(&gShared.nEmpty);
			sem_post(&gShared.producerMutex);
			return NULL;
		}

		gShared.buff[gShared.nput++%N] = gShared.nputval++;
		(*((int *)arg))++;

		sem_post(&gShared.producerMutex);
		sem_post(&gShared.nStored);
	}
	return NULL;
}

void* consumer(void *arg)
{
	for (;;)
	{
		// 检查是否已消费完
		sem_wait(&gShared.consumerMutex);
		if (gShared.ngetval >= gItems)
		{
			sem_post(&gShared.consumerMutex);
			return NULL;
		}

		// 完成一次消费
		sem_wait(&gShared.nStored);

		if (gShared.buff[gShared.nget%N] != gShared.ngetval)
		{
			printf("confilict! index=%d  curval=%d  legalval=%d\n",
				   gShared.nget%N, gShared.buff[gShared.nget%N], gShared.nget);
		}

		gShared.nget++;
		gShared.ngetval++;
		(*((int *)arg))++;

		sem_post(&gShared.nEmpty);
		sem_post(&gShared.consumerMutex);
	}
	return NULL;
}
