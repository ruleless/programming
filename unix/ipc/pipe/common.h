#ifndef __COMMON_H__
#define __COMMON_H__

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIFO_PATH "/tmp/ServerFIFO"
#define FIFO_ECHO "/tmp/ECHOFIFO."

#define MAX_BUF 256

extern void errQuit();

#endif
