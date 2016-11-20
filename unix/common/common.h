#ifndef __UNIX_COMMON_H__
#define __UNIX_COMMON_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h> 
#include <math.h>
#include <assert.h> 
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>  
#include <cstring>  
#include <vector>
#include <map>
#include <list>
#include <set>
#include <deque>
#include <queue>
#include <limits>
#include <algorithm>
#include <utility>
#include <functional>
#include <cctype>
#include <iterator>

#include <errno.h>
#include <float.h>
#include <pthread.h>	
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <netdb.h>
#include <iconv.h>
#include <langinfo.h>
#include <stdint.h>
#include <signal.h>
#include <dirent.h>
#include <net/if.h>
#include <netinet/in.h>
#include <netinet/tcp.h> 
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <tr1/unordered_map>
#include <tr1/functional>
#include <tr1/memory>
#include <linux/types.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/uio.h>
#include <sys/resource.h>

// 常量定义
#ifndef NAME_PATH
# define NAME_PATH 255
#endif

#ifndef NAME_MAX
# define NAME_MAX 255
#endif

#ifndef MAX_NAME
# define MAX_NAME 256
#endif

#ifndef MAX_IP
# define MAX_IP 50
#endif

#ifndef MAX_BUF
# define MAX_BUF 256
#endif

#ifndef MAX_PATH
# define MAX_PATH 260
#endif

/* 输出错误信息并退出
 * @param msg: 错误信息
 * @param bErrno: 是否打印errno错误消息
 */
void errSys(const char *msg, bool bErrno = true);

void errQuit(const char *msg, bool bErrno = true);

/* 给指定区域加读锁(不阻塞)
 */
#define regReadRecLock(fd, offset, whence, len) \
	regRecLock(fd, F_SETLK, F_RDLCK, offset, whence, len)
/* 给指定区域加读锁(阻塞)
 */
#define regReadWRecLock(fd, offset, whence, len) \
	regRecLock(fd, F_SETLKW, F_RDLCK, offset, whence, len)
/* 给指定区域加写锁(不阻塞)
 */
#define regWriteRecLock(fd, offset, whence, len) \
	regRecLock(fd, F_SETLK, F_WRLCK, offset, whence, len)
/* 给指定区域加写锁(阻塞)
 */
#define regWriteWRecLock(fd, offset, whence, len) \
	regRecLock(fd, F_SETLKW, offset, whence, len)

/* 注册记录锁
 */
int regRecLock(int fd, int cmd, int type, off_t offset, int whence, off_t len);

/* 遍历目录
 */
typedef bool (*FileHandler)(const char *pathname);
int traverseDir(const char *pathname, FileHandler handler);

#endif // __SNAILUNIX_H__
