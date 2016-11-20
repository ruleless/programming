#include "shmdef.h"

int main(int argc, char *argv[])
{
	shm_unlink(SHMNAME);
	exit(0);
}
