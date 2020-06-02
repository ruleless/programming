#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 9
#define Grid 3
static int figure[N][N];

bool dfs(int index)
{
	if (index >= N*N)
	{
		return true;
	}

	int i = index/N;
	int j = index%N;

	bool bExist[N+1];
	memset(bExist, false, sizeof(bExist));
	for (int k = 0; k < j; ++k)
	{
		bExist[figure[i][k]] = true;
	}
	for (int k = 0; k < i; ++k)
	{
		bExist[figure[k][j]] = true;
	}
	int begI = (i/Grid) * (Grid);
	int begJ = (j/Grid) * (Grid);
	for (int ii = begI; ii < i; ++ii)
	{
		for (int jj = begJ; jj < begJ+Grid; ++jj)
		{
			bExist[figure[ii][jj]] = true;
		}
	}

	int randArr[N];
	int n = 0;
	for (int k = 1; k <= N; ++k)
	{
		if (!bExist[k])
			randArr[n++] = k;
	}

	if (n > 0)
	{
		int count = 0;
		for (; count < n; ++count)
		{
			int k = rand()%(n-count);
			figure[i][j] = randArr[k];
			if (!dfs(index+1))
			{
				randArr[k] = randArr[n-1];
			}
			else
			{
				break;
			}
		}
		if (count == n)
			return false;
		return true;
	}
	else
	{
		return false;
	}
}

int main(int argc, char *argv[])
{
	srand((unsigned)time(NULL));

	int n = 0;
	printf("请输入您要生成的题目个数：\n");
	scanf("%d", &n);
	while (n--)
	{
		memset(figure, 0, sizeof(figure));
		printf("dfs: %d\n", dfs(0));
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				printf("%d ", figure[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}
