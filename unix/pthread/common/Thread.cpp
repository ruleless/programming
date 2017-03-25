
#include "common.h"
#include "Thread.h"

static void* threadFunc(void*);

Thread::Thread()
		:mTID(0)
		,mStatus(S_Unknown)
{
}

Thread::~Thread() {
}

void Thread::start() {
	if (mStatus != S_Running) {
		if (0 == pthread_create(&mTID, NULL, threadFunc, this)) {
			_setStatus(S_Running);
		}
	}
}

void Thread::stop() {
	if (mStatus == S_Running) {
		mStatus = S_Stopped;
	}
}

Thread::Status Thread::getStatus() const {
	return mStatus;
}

pthread_t Thread::getThreadID() const {
	return mTID;
}

void Thread::_setStatus(Status s) {
	mStatus = s;
}

bool Thread::run() {
	return true;
}

static void* threadFunc(void* arg) {
	Thread *pThread = (Thread *)arg;
	while (pThread->getStatus() == Thread::S_Running) {
		if (pThread->run()) {
			pThread->_setStatus(Thread::S_Stopped);
		}
	}

	return NULL;
}
