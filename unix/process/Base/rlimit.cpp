
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

#define PRINT_RLIMIT(res) printrlimit(#res, res)
void printrlimit(const char* name, int resID);

int main(int argc, char *argv[])
{
	PRINT_RLIMIT(RLIMIT_AS);
	PRINT_RLIMIT(RLIMIT_CORE);
	PRINT_RLIMIT(RLIMIT_CPU);
	PRINT_RLIMIT(RLIMIT_DATA);
	PRINT_RLIMIT(RLIMIT_FSIZE);
	PRINT_RLIMIT(RLIMIT_LOCKS);
	PRINT_RLIMIT(RLIMIT_MEMLOCK);
	PRINT_RLIMIT(RLIMIT_NOFILE);
	#ifdef RLIMIT_NPPROC
	PRINT_RLIMIT(RLIMIT_NPPROC);
	#endif
	PRINT_RLIMIT(RLIMIT_RSS);
	#ifdef RLIMIT_SBSIZE
	PRINT_RLIMIT(RLIMIT_SBSIZE);
	#endif
	PRINT_RLIMIT(RLIMIT_STACK);
	#ifdef RLIMIT_VMEM
	PRINT_RLIMIT(RLIMIT_VMEM);
	#endif
	exit(0);
}

void printrlimit(const char* name, int resID)
{
	struct rlimit limit;
	if (getrlimit(resID, &limit) != 0)
	{
		printf("getrlimit error. resid=%d\n", resID);
		exit(1);
	}

	printf("%14s    curlim:", name);
	if (limit.rlim_cur == RLIM_INFINITY)
	{
		printf("(infinity)");
	}
	else
	{
		printf("%10ld", limit.rlim_cur);
	}

	printf("    maxlim:");
	if (limit.rlim_max == RLIM_INFINITY)
	{
		printf("(infinity)");
	}
	else
	{
		printf("%10ld", limit.rlim_max);
	}
	putchar('\n');
}
