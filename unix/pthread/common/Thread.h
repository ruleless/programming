
#ifndef __THREAD_H__
#define __THREAD_H__

#include <unistd.h>
#include <pthread.h>

class Thread {
public:
	enum Status{
		S_Unknown,
		S_Running,
		S_Stopped,
	};

	Thread();
	virtual ~Thread();

	void start();
	void stop();

	Status getStatus() const;
	pthread_t getThreadID() const;

	void _setStatus(Status s);

	virtual bool run();
protected:
	pthread_t mTID;
	Status mStatus;
};

#endif
