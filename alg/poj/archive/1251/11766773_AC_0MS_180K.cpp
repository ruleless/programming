#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100
#define INF 0xFFFF
static int g_edge[N][N], n;

int prime()
{
	bool vis[N];
	int weight[N], res = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i < n; ++i)
		weight[i] = g_edge[0][i];
	vis[0] = true;
	weight[0] = 0;
	for (int j = 1; j <= n - 1; ++j)
	{
		int beg = 1;
		while (vis[beg]) beg++;
		int k = beg;
		for (int i = beg + 1; i < n; ++i)
		{
			if (!vis[i] && weight[i] < weight[k])
				k = i;
		}
		res += weight[k];
		vis[k] = true;
		for (int i = beg; i < n; ++i)
		{
			if (!vis[i] && g_edge[k][i] < weight[i])
				weight[i] = g_edge[k][i];
		}
	}
	return res;
}

int main(int argc, char* argv[])
{
	while (scanf("%d", &n) != EOF && n)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i == j)
					g_edge[i][j] = 0;
				else
					g_edge[i][j] = INF;
			}
		}
		for (int i = 0; i < n - 1; ++i)
		{
			char s[10], t[10];
			int num, price;
			scanf("%s%d", s, &num);
			while (num--)
			{
				scanf("%s%d", &t, &price);
				g_edge[s[0] - 'A'][t[0] - 'A'] = g_edge[t[0] - 'A'][s[0] - 'A'] = price;
			}
		}
		printf("%d\n", prime());
	}
	return 0;
}