// 多生产者-单消费者
#include <pthread.h>
#include "common.h"

#include "SampleDef.h"

int gItems = 0;
Shared gShared;

void* producer(void *arg);
void* consumer(void *arg);

int main(int argc, char *argv[])
{
	gItems = 1;
	if (argc > 1)
		gItems = min(atoi(argv[1]), N);

	int nProducer = MAX_THREAD;
	if (argc > 2)
		nProducer = min(nProducer, atoi(argv[2]));

	pthread_t tidProducers[MAX_THREAD];
	int execTimes[MAX_THREAD];
	for (int i = 0; i < nProducer; ++i)
	{
		execTimes[i] = 0;
		pthread_create(&tidProducers[i], NULL, producer, &execTimes[i]);
	}

	pthread_t tidConsumer;
	pthread_create(&tidConsumer, NULL, consumer, NULL);

	for (int i = 0; i < nProducer; ++i)
	{
		pthread_join(tidProducers[i], NULL);
	}
	pthread_join(tidConsumer, NULL);

	for (int i = 0; i < nProducer; ++i)
	{
		printf("producer %d run %d times\n", i, execTimes[i]);
	}

	exit(0);
}

void* producer(void *arg)
{
	for (;;)
	{
		pthread_mutex_lock(&gShared.producerMutex);
		if (gShared.nputval >= gItems)
		{
			pthread_mutex_unlock(&gShared.producerMutex);
			return NULL;
		}
		gShared.buff[gShared.nput++] = gShared.nputval++;
		pthread_mutex_unlock(&gShared.producerMutex);

		pthread_mutex_lock(&gShared.readyMutex);
		++gShared.nReady;
		pthread_mutex_unlock(&gShared.readyMutex);

		if (1 == gShared.nReady)  // 唤醒消费线程
			pthread_cond_signal(&gShared.cond);

		(*((int *)arg))++;
	}
	return NULL;
}

void* consumer(void *arg)
{
	for (int i = 0; i < gItems; ++i)
	{
		pthread_mutex_lock(&gShared.readyMutex);
		while (gShared.nReady <= 0)
		{
			pthread_cond_wait(&gShared.cond, &gShared.readyMutex);
		}

		--gShared.nReady;
		if (gShared.buff[i] != i)
		{
			printf("conflict! index=%d curval=%d legalval=%d\n", i%N, gShared.buff[i%N], i);
		}
		
		pthread_mutex_unlock(&gShared.readyMutex);
	}
	return NULL;
}
