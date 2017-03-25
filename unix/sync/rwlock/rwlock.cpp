#include "rwlock.h"
#include "common.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int Rwlock::rdlock() {
	int res = 0;

	res = pthread_mutex_lock(&mutex);
	if (res != 0) {
		return res;
	}

	++waitReaders;
	while (0 == res && (-1 == refCount || waitWriters > 0)) // 写入锁被占有，或有等待的写入者
	{
		res = pthread_cond_wait(&rdCond, &mutex);
	}
	--waitReaders;
	
	if (0 == res) // 获取读出锁
	{
		++refCount;	 
	}

	pthread_mutex_unlock(&mutex);
	return res;
}

int Rwlock::tryrdlock() {
	int res = 0;
	
	res = pthread_mutex_lock(&mutex);
	if (res != 0)
	{
		return res;
	}

	if (-1 == refCount || waitWriters > 0) // 写入锁被占有，或有等待的写入者
	{
		res = EBUSY;
	}
	else
	{
		++refCount;
	}

	pthread_mutex_unlock(&mutex);
	return res;
}

int Rwlock::wrlock()
{
	int res = 0;

	res = pthread_mutex_lock(&mutex);
	if (res != 0)
	{
		return res;
	}

	++waitWriters;
	while (0 == res && refCount != 0) // 等待读写锁空闲
	{
		res = pthread_cond_wait(&wrCond, &mutex);
	}
	--waitWriters;

	if (0 == res) // 获取写入锁
	{
		refCount = -1;
	}
		
	pthread_mutex_unlock(&mutex);
	return res;
}

int Rwlock::trywrlock()
{
	int res = 0;

	res = pthread_mutex_lock(&mutex);
	if (res != 0)
	{
		return 0;
	}

	if (0 == refCount) // 获取写入锁
	{
		refCount = -1;
	}
	else
	{
		res = EBUSY;
	}

	pthread_mutex_unlock(&mutex);
	return res;
}

int Rwlock::unlock()
{
	int res = 0;

	res = pthread_mutex_lock(&mutex);
	if (res != 0)
	{
		return res;
	}

	// 释放读写锁
	if (-1 == refCount)
	{
		refCount = 0;
	}
	else if (refCount > 0)
	{
		--refCount;
	}
	else
	{
		char szBuff[256] = {0};
		snprintf(szBuff, sizeof(szBuff), "unlock rwlock error! refcount=%d!", refCount);
		errSys(szBuff, false);
	}

	// 通知其他等待着的写入者或读出者
	if (waitWriters > 0)
	{
		if (0 == refCount)
		{
			pthread_cond_signal(&wrCond);
		}
	}
	else if (waitReaders > 0)
	{
		pthread_cond_broadcast(&rdCond);
	}

	pthread_mutex_unlock(&mutex);
	return res;
}
