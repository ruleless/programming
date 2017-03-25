#ifndef __STRSTR_HPP__
#define __STRSTR_HPP__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

namespace alg
{
int strstr(const char* str, const char* substr)
{
	int n = strlen(str);
	int subn = strlen(substr);
	for (int i = 0; i < n; ++i)
	{
		int j = 0;
		for (; j < subn && i+j < n; ++j)
		{
			if (substr[j] != str[i+j])
				break;
		}
		if (j == subn)
			return i;
	}
	return -1;
}
}

#endif // __STRSTR_HPP__
