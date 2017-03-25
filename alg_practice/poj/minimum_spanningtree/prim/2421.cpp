#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 105

int prim(int edge[N][N], int n)
{
	bool bSets[N];
	int minEdge[N];

	memset(bSets, 0, sizeof(bSets));
	bSets[1] = true;
	minEdge[1] = 0;
	for (int i = 2; i <= n; ++i)
	{
		minEdge[i] = edge[1][i];
	}

	int res = 0;
	for (int i = 1; i <= n-1; ++i)
	{
		int u = 1;
		while (bSets[u]) ++u;
		for (int j = u+1; j <= n; ++j)
		{
			if (!bSets[j] && minEdge[j] >= 0 && minEdge[j] < minEdge[u])
				u = j;
		}
		if (minEdge[u] < 0)
			return -1;

		res += minEdge[u];
		bSets[u] = true;
		for (int v = 1; v <= n; ++v)
		{
			if (!bSets[v] && edge[u][v] >= 0 && edge[u][v] < minEdge[v])
				minEdge[v] = edge[u][v];
		}
	}
	return res;
}

int main(int argc, char *argv[])
{
	freopen("in.txt", "r", stdin);

	int edge[N][N], n = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			scanf("%d", &edge[i][j]);
		}
	}
   
	int Q;
	scanf("%d", &Q);
	while (Q--)
	{
		int s, t;
		scanf("%d%d", &s, &t);
		edge[s][t] = edge[t][s] = 0;
	}

	printf("%d\n", prim(edge, n));
	
	return 0;
}
