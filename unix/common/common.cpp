#include "common.h"

void errSys(const char *msg, bool bErrno)
{
	const char *preMsg = "";
	if (msg) {
		preMsg = msg;
	}

	if (bErrno) {
		fprintf(stderr, "%s  %s\n", preMsg, strerror(errno));
	}
	else {
		fprintf(stderr, "%s\n", preMsg);
	}
	exit(1);
}

void errQuit(const char *msg, bool bErrno)
{
	return errSys(msg, bErrno);
}

int regRecLock(int fd, int cmd, int type, off_t offset, int whence, off_t len)
{
	struct flock lock;
	lock.l_type = type;
	lock.l_start = offset;
	lock.l_whence = whence;
	lock.l_len = len;
	lock.l_pid = 0;
	return fcntl(fd, cmd, &lock);
}

int traverseDir(const char *pathname, FileHandler handler)
{
	struct stat fileStat;
	if (lstat(pathname, &fileStat) < 0)
	{
		return -1;
	}

	if (!handler(pathname))
	{
		return 0;
	}
	if (!S_ISDIR(fileStat.st_mode))
	{
		return 0;
	}

	DIR *dir = opendir(pathname);
	if (dir != NULL)
	{
		char subpath[NAME_PATH+1];
		memset(subpath, 0, sizeof(subpath));
		strncpy(subpath, pathname, NAME_PATH);
		char *ptr = subpath;
		ptr += strlen(subpath);
		if (ptr > subpath && *(ptr-1) != '/')
		{
			*ptr++ = '/';
		}

		struct dirent *ent = readdir(dir);
		while (ent != NULL)
		{
			if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
			{
				ent = readdir(dir);
				continue;
			}

			strncpy(ptr, ent->d_name, NAME_PATH-(int)(ptr-subpath));
			*(ptr+strlen(ent->d_name)) = '\0';
			traverseDir(subpath, handler);

			ent = readdir(dir);
		}
		closedir(dir);
	}

	return 0;
}
