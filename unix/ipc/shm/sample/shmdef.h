#ifndef __SHMDEF_H__
#define __SHMDEF_H__

#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

#define SHMNAME "/shmtest"

#define N 256

#endif
