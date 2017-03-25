#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

#include "common.h"

static bool printPath(const char *pathname)
{
	printf("%s\n", pathname);
	return true;
}

int main(int argc, char *argv[])
{
	for (int i = 1; i < argc && argv[i]; ++i)
	{
		traverseDir(argv[i], printPath);
	}
	
	exit(0);
}
