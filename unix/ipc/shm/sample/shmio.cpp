#include "shmdef.h"

#define MAX_SIZE 8196

int main(int argc, char *argv[])
{
	const char *fileName = "tmp";
	if (argc > 1)
		fileName = argv[1];

	int fd = open(fileName, O_RDWR|O_CREAT, 0644);
	if (fd < 0)
		errQuit("open file failed.");

	char *ptr = (char *)mmap(NULL, MAX_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	ftruncate(fd, 0);

	int n = 0;
	int cur = 0;
	char buff[MAX_SIZE];
	while ((n=read(STDIN_FILENO, buff, MAX_SIZE)) > 0)
	{
		n = min(n, MAX_SIZE-cur);
		ftruncate(fd, cur+n);
		memcpy(ptr+cur, buff, n);
		cur += n;

		if (cur >= MAX_SIZE)
			break;
	}

	exit(0);
}
