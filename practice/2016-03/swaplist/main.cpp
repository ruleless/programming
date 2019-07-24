#include "swaplist.hpp"

static SwapList<int> _gList;

void printInt(int val)
{
	printf("%d\n", val);
}

static void* _thread(void *arg)
{
	_gList._waitForFlush();
	_gList.flush(printInt);
	return NULL;
}

int main(int argc, char *argv[])
{
	pthread_t tid;
	pthread_create(&tid, NULL, &_thread, NULL);

	for (int i = 0; i < 50; ++i)
	{
		_gList.push(i);
		struct timeval tm;
		tm.tv_sec = 0;
		tm.tv_usec = 1000*10;
		select(0, NULL, NULL, NULL, &tm);
	}

	pthread_join(tid, NULL);
	exit(0);
}
