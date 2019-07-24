
#include "unp.h"

int readn(int fd, void *pData, size_t len)
{
	char *ptr = (char *)pData;
	size_t leftByte = len;

	while (leftByte > 0)
	{
		int n = read(fd, ptr, leftByte);
		if (n < 0)
		{
			if (errno == EINTR)
				n = 0;
			else
				return -1;
		}
		else if (n == 0)
		{
			break;
		}

		leftByte -= n;
		ptr += n;
	}

	return len - leftByte;
}

int readline(int fd, void *pData, size_t len)
{
	char *ptr = (char *)pData;
	size_t readByte = 0;

	for (readByte = 1; readByte < len; ++readByte)
	{
	  again:
		char c;
		int n = read(fd, &c, 1);
		if (n == 1)
		{
			*ptr++ = c;
			if (c == '\n')
				break;
		}
		else if (n == 0)
		{
			*ptr = '\0';
			return readByte-1;
		}
		else
		{
			if (errno == EINTR)
				goto again;
			else
				return -1;
		}
	}

	*ptr = '\0';
	return readByte;
}

int writen(int fd, const void *pData, size_t len)
{
	const char *ptr = (const char *)pData;
	size_t leftByte = len;

	while (leftByte > 0)
	{
		int n = write(fd, ptr, leftByte);
		if (n < 0)
		{
			if (errno == EINTR)
				n = 0;
			else
				return -1;
		}
		else if (n == 0)
		{
			return -1;
		}

		leftByte -= n;
		ptr += n;
	}

	return len-leftByte;
}
