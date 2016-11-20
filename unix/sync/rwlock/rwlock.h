#ifndef __RWLOCK_H__
#define __RWLOCK_H__

#include <pthread.h>

class Rwlock {
  public:
	Rwlock() : mutex(PTHREAD_MUTEX_INITIALIZER)
			 , wrCond(PTHREAD_COND_INITIALIZER)
			 , rdCond(PTHREAD_COND_INITIALIZER)
			 , waitWriters(0)
			 , waitReaders(0)
			 , refCount(0)
	{
	}

	~Rwlock() {}

	int rdlock();
	int tryrdlock();

	int wrlock();
	int trywrlock();

	int unlock();
  private:
	pthread_mutex_t mutex;
	pthread_cond_t wrCond;
	pthread_cond_t rdCond;

	int waitWriters;
	int waitReaders;
	int refCount;
};

#endif
