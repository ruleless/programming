#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

int main(int argc, char *argv[])
{
	Queue<int, 5> que;
	for (int i = 1; i < argc; ++i)
	{
		int n = atoi(argv[i]);
		if (que.pushBack(n))
		{
			printf("push ok:%d\n", n);
		}
		else
		{
			printf("push failed:%d\n", n);
		}
	}

	while(!que.empty())
	{
		int n = 0;
		que.popFront(&n);
		printf("%d ", n);
	}
	printf("\n");

	exit(0);
}
