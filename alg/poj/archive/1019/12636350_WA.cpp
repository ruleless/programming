/********************************************************************
** filename: main.cpp
** author:   liuyang <ruleless@126.com>
** created:  2013/12/18   22:15
	
** purpose:  Base工程测试文件
*********************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>

#if 0
int main(int argc, char* arg[])
{
	getchar();
	getchar();
	return 0;
}
#endif

int main(int argc, char* argv[])
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		__int64 k = 0;
		scanf("%lld", &k);
		__int64 n = floor((sqrtl(1 + 8 * k) - 1) / 2.f);
		__int64 m = __int64(n * __int64((n + 1))) / 2;
		int res = 0;
		if (k == m)
		{
			res = n;
		}
		else
		{
			res = k - m;
		}
		printf("%lld\n", res);
	}
	return 0;
}