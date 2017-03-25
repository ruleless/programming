#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

template<typename T, int N> class Queue
{
  public:
	Queue()
	{
		memset(mQueue, 0, sizeof(mQueue));
		mFront = 0;
		mRear = 0;
	}

	Queue(const Queue &q)
	{
		memcpy(mQueue, q.mQueue, sizeof(mQueue));
		mFront = q.mFront;
		mRear = q.mRear;
	}

	Queue& operator=(const Queue &q)
	{
		memcpy(mQueue, q.mQueue, sizeof(mQueue));
		mFront = q.mFront;
		mRear = q.mRear;
	}

	bool empty() const
	{
		return mFront == mRear;
	}

	bool full() const
	{
		return size() == N;
	}

	int size() const
	{
		return (N+1+mRear-mFront) % (N+1);
	}
			
	bool pushBack(const T &e)
	{
		if (full())
		{
			return false;
		}

		mQueue[mRear] = e;
		mRear = (mRear+1) % (N+1);
		return true;
	}

	bool popFront(T *e)
	{
		if (empty())
		{
			return false;
		}

		*e = mQueue[mFront];
		mFront = (mFront+1) % (N+1);
		return true;
	}
	bool popFront(T &e)
	{
		if (empty())
		{
			return false;
		}

		e = mQueue[mFront];
		mFront = (mFront+1) % (N+1);
		return true;
	}

	void clear()
	{
		memset(mQueue, 0, sizeof(mQueue));
		mFront = 0;
		mRear = 0;
	}
  protected:
	T mQueue[N+1];
	int mFront;
	int mRear;
};

#endif
