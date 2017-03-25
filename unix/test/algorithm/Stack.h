#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

template<typename T, int N> class Stack
{
public:
	Stack()
	{
		memset(mStack, 0, sizeof(mStack));
		mTop = 0;			   
	}

	Stack(const Stack &s)
	{
		memcpy(mStack, s.mStack, sizeof(mStack));
		mTop = s.mTop;
	}

	Stack& operator=(const Stack &s)
	{
		memcpy(mStack, s.mStack, sizeof(mStack));
		mTop = s.mTop;
	}

	int empty() const
	{
		return mTop == 0;
	}

	int full() const
	{
		return size() == N;
	}

	int size() const
	{
		return mTop;
	}

	bool push(const T &e)
	{
		if (full())
			return false;
		
		mStack[mTop++] = e;
		return true;
	}

	bool pop(T *e)
	{
		if (empty())
			return false;
		
		*e = mStack[--mTop];
		return true;
	}
	bool pop(T &e)
	{
		if (empty())
			return false;

		e = mStack[--mTop];
		return true;
	}	

	void clear()
	{
		memset(mStack, 0, sizeof(mStack));
		mTop = 0;
	}
private:
	T mStack[N];
	int mTop;
};

#endif
