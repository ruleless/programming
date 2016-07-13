#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum(int a, int b)
{
	int c = a+b;
	return c;
}

int main(int argc, char* argv[])
{
	if (argc == 3)
	{
		int a = atoi(argv[1]);
		int b = atoi(argv[2]);
		int s = sum(a, b);
		printf("%d\n", s);
	}
	return 0;
}