
#ifndef __UNP_H__
#define __UNP_H__

#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int readn(int fd, void *pData, size_t len);
int readline(int fd, void *pData, size_t len);
int writen(int fd, const void *pData, size_t len);

#endif
