#include "shmdef.h"

int main(int argc, char *argv[])
{
	int fd = shm_open(SHMNAME, O_RDWR|O_CREAT|O_EXCL, 0644);
	if (fd < 0)
		errQuit("open shm failed.");
	printf("create shm sucess.\n");
	exit(0);
}
