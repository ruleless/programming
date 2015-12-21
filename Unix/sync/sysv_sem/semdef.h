#ifndef __SEMDEF_H__
#define __SEMDEF_H__

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SEM_PATH "./semcreate"

union semun
{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
};

extern void errQuit();

#endif
