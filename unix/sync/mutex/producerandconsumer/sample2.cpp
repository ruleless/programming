#include <pthread.h>
#include "SampleDef.h"
#include "common.h"

int gItems = 1;
Shared gShared;

void* producer(void *arg);
void* consumer(void *arg);

int main(int argc, char *argv[])
{
	if (argc > 1)
		gItems = min(atoi(argv[1]), N);

	int nProducer = MAX_THREAD;
	if (argc > 2)
		nProducer = min(atoi(argv[2]), MAX_THREAD);
	int nConsumer = MAX_THREAD;
	if (argc > 3)
		nProducer = min(atoi(argv[3]), MAX_THREAD);

	pthread_t tidProducers[MAX_THREAD];
	int execTimesOfProducer[MAX_THREAD];
	for (int i = 0; i < nProducer; ++i)
	{
		execTimesOfProducer[i] = 0;
		pthread_create(&tidProducers[i], NULL, producer, &execTimesOfProducer[i]);
	}

	pthread_t tidConsumers[MAX_THREAD];
	int execTimesOfConsumer[MAX_THREAD];
	for (int i = 0; i < nConsumer; ++i)
	{
		execTimesOfConsumer[i] = 0;
		pthread_create(&tidConsumers[i], NULL, consumer, &execTimesOfConsumer[i]);
	}

	for (int i = 0; i < nProducer; ++i)
	{
		pthread_join(tidProducers[i], NULL);
	}

	for (int i = 0; i < nConsumer; ++i)
	{
		pthread_join(tidConsumers[i], NULL);
	}

	for (int i = 0; i < nProducer; ++i)
	{
		printf("producer %d run %d times\n", i, execTimesOfProducer[i]);
	}
	for (int i = 0; i < nConsumer; ++i)
	{
		printf("consumer %d run %d times\n", i, execTimesOfConsumer[i]);
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

		if (1 == gShared.nReady)
			pthread_cond_broadcast(&gShared.cond);

		(*((int *)arg))++;
	}
	return NULL;
}

void* consumer(void *arg)
{
	for (;;)
	{
		pthread_mutex_lock(&gShared.readyMutex);
		while (gShared.nReady <= 0 && gShared.ngetval < gItems)
		{
			pthread_cond_wait(&gShared.cond, &gShared.readyMutex);
		}
		if (gShared.ngetval >= gItems)
		{
			pthread_mutex_unlock(&gShared.readyMutex);
			return NULL;
		}

		--gShared.nReady;
		if (gShared.buff[gShared.nget] != gShared.ngetval)
		{
			printf("conflict! index=%d curval=%d legalval=%d\n", gShared.nget, gShared.buff[gShared.nget], gShared.ngetval);
		}
		++gShared.nget;
		++gShared.ngetval;

		pthread_mutex_unlock(&gShared.readyMutex);

		(*((int *)arg))++;
	}
	return NULL;
}
