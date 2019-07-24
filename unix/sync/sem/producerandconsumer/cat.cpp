// 多缓冲区示例(单生产者-单消费者)
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

#define BUFF_SIZE 256
#define QSIZE 8

struct Shared
{
	struct
	{
		char buff[BUFF_SIZE];
		int n;
	} que[QSIZE];

	sem_t nEmpty, nStored;

	Shared()
	{
		memset(que, 0, sizeof(que));
	}
};
struct Shared gShared;

void* producer(void *arg);
void* consumer(void *arg);

int main(int argc, char *argv[])
{
	sem_init(&gShared.nEmpty, 0, QSIZE);
	sem_init(&gShared.nStored, 0, 0);

	pthread_t tidProducer;
	int execTimesOfProducer = 0;
	pthread_create(&tidProducer, NULL, producer, &execTimesOfProducer);

	pthread_t tidConsumer;
	int execTimesOfConsumer = 0;
	pthread_create(&tidConsumer, NULL, consumer, &execTimesOfConsumer);

	pthread_join(tidProducer, NULL);
	pthread_join(tidConsumer, NULL);

	printf("producer exec %d times\n", execTimesOfProducer);
	printf("consumer exec %d times\n", execTimesOfConsumer);

	sem_destroy(&gShared.nEmpty);
	sem_destroy(&gShared.nStored);

	exit(0);
}

void* producer(void *arg)
{
	int i = 0;
	for (;;)
	{
		sem_wait(&gShared.nEmpty);

		gShared.que[i].n = read(STDIN_FILENO, gShared.que[i].buff, BUFF_SIZE);
		if (gShared.que[i].n < 0)
		{
			errQuit("read error!");
		}
		if (gShared.que[i].n == 0)
		{
			sem_post(&gShared.nStored);
			return NULL;
		}

		i = (i+1)%QSIZE;
		(*((int *)arg))++;

		sem_post(&gShared.nStored);
	}
	return NULL;
}

void* consumer(void *arg)
{
	int i = 0;
	for (;;)
	{
		sem_wait(&gShared.nStored);

		if (0 == gShared.que[i].n)
		{
			return NULL;
		}
		if (write(STDOUT_FILENO, gShared.que[i].buff, gShared.que[i].n) != gShared.que[i].n)
		{
			errQuit("write error!");
		}
		i = (i+1)%QSIZE;
		(*((int *)arg))++;

		sem_post(&gShared.nEmpty);
	}
	return NULL;
}
