#ifndef __SAMPLEDEF_H__
#define __SAMPLEDEF_H__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000000
#define MAX_THREAD 16

struct Shared
{
	int buff[N];
	int nput;
	int nputval;
	pthread_mutex_t producerMutex;

	int nReady;
	pthread_mutex_t readyMutex;
	pthread_cond_t cond;

	int nget;
	int ngetval;

	Shared()
	{
		memset(buff, -1, sizeof(buff));
		nput = 0;
		nputval = 0;
		nReady = 0;
		nget = 0;
		ngetval = 0;
	}
};

#endif
