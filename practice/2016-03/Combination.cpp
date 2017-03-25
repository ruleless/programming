#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int _getCombination(int cur, int level, int m, int n, int *r)
{	
	r[level] = cur;
	if (level >= n-1)
	{
		for (int i = 0; i < n; ++i)
		{
			printf("%d ", r[i]);
		}
		printf("\n");
		return 1;
	}

	int totalCount = 0;
	while (++cur < m)
	{
		if (n-level-1 > m-cur)
		{
			break;
		}
		totalCount += _getCombination(cur, level+1, m, n, r);
	}
	return totalCount;
}

int getCombination(int m, int n)
{
	int totalCount = 0;
	int *r = new int[m];
	for (int i = 0; i < m; ++i)
	{
		totalCount += _getCombination(i, 0, m, n, r);
	}
	delete [] r;
	return totalCount;
}
