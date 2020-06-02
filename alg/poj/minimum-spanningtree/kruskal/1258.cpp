#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 105

int edge[N][N], n;

struct Edge
{
	int u, v, w;
} e[N*N];
int ecnt;

int cmp(const void *a, const void *b)
{
	return ((const Edge *)a)->w - ((const Edge *)b)->w;
}

int Find(int);
void Union(int, int);
int kruskal()
{
	qsort(e, ecnt, sizeof(Edge), cmp);

	int conEdges = 0;
	int wSum = 0;
	for (int i = 0; i < ecnt; ++i)
	{
		if (Find(e[i].u) != Find(e[i].v))
		{
			Union(e[i].u, e[i].v);
			wSum += e[i].w;
			if (++conEdges >= n-1)
				break;
		}
	}
	return wSum;
}

int parent[N];

int Find(int a)
{
	if (parent[a] < 0)
		return a;
	int root = Find(parent[a]);
	parent[a] = root;
	return root;
}

void Union(int a, int b)
{
	int rootA = Find(a);
	int rootB = Find(b);
	if (rootA == rootB)
		return;

	if (rootA < rootB)
	{
		parent[rootA] += parent[rootB];
		parent[rootB] = rootA;
	}
	else
	{
		parent[rootB] += parent[rootA];
		parent[rootA] = rootB;
	}
}

int main(int argc, char *argv[])
{
	freopen("in.txt", "r", stdin);
	while (scanf("%d", &n) != EOF && n > 0)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				scanf("%d", &edge[i][j]);
			}
		}

		memset(parent, -1, sizeof(parent));
		ecnt = 0;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = i+1; j <= n; ++j)
			{
				e[ecnt].u = i;
				e[ecnt].v = j;
				e[ecnt].w = edge[i][j];
				++ecnt;
			}
		}

		printf("%d\n", kruskal());
	}
	return (0);
}
