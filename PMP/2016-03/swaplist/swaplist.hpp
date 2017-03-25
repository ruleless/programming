#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <list>

#ifndef __SWAPLIST_H__
#define __SWAPLIST_H__

template <class T>
class SwapList
{
  protected:
	typedef std::list<T> TList;

	TList mList1;
	TList mList2;
	TList *mInList;
	TList *mOutList;

	pthread_mutex_t mMutex;
	pthread_cond_t mCond;
  public:
    SwapList()
			:mList1()
			,mList2()
			,mInList(&mList1)
			,mOutList(&mList2)
	{
	}
	
    virtual ~SwapList() {}

	void push(T val)
	{
		pthread_mutex_lock(&this->mMutex);
		
		this->mInList->push_back(val);
		pthread_cond_signal(&this->mCond);
		
		pthread_mutex_unlock(&this->mMutex);
	}

	typedef void (* Callback)(T val);
	void flush(Callback cb)
	{
		pthread_mutex_lock(&this->mMutex);
		if (this->mInList->empty())
		{
			pthread_mutex_unlock(&this->mMutex);
			return;
		}
		
		TList *temp = this->mInList;
		this->mInList = this->mOutList;
		this->mOutList = temp;
		
		pthread_mutex_unlock(&this->mMutex);

		typename TList::iterator it = this->mOutList->begin();
		for (; it != this->mOutList->end(); ++it)
		{
			cb(*it);
		}
		this->mOutList->clear();
	}

	void _waitForFlush()
	{
		pthread_mutex_lock(&this->mMutex);
		while (this->mInList->empty())
		{
			pthread_cond_wait(&this->mCond, &this->mMutex);
		}		
		pthread_mutex_unlock(&this->mMutex);
	}
};

#endif // __SWAPLIST_H__
