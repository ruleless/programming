#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000
static struct Edge
{
	int u, v, w;
}g_edge[N];
static int n, g_ecount;
static int g_parent[N];

int Find(int a)
{
	if (g_parent[a] < 0)
	{
		return a;
	}
	int r = Find(g_parent[a]);
	g_parent[a] = r;
	return r;
}

void Union(int a, int b)
{
	int x = Find(a);
	int y = Find(b);
	if (g_parent[x] < g_parent[y])
	{
		g_parent[x] += g_parent[y];
		g_parent[y] = x;
	}
	else
	{
		g_parent[y] += g_parent[x];
		g_parent[x] = y;
	}
}

int cmp(const void* a, const void* b)
{
	const struct Edge* s_a = (const struct Edge*)a;
	const struct Edge* s_b = (const struct Edge*)b;
	return s_a->w - s_b->w;
}

int kruscal()
{
	int res = 0, count = 0;
	qsort(g_edge, g_ecount, sizeof(struct Edge), cmp);
	for (int i = 0; i < g_ecount; ++i)
	{
		if (Find(g_edge[i].u) == Find(g_edge[i].v))
			continue;

		res += g_edge[i].w;
		Union(g_edge[i].u, g_edge[i].v);
		if (++count == n - 1)
			break;
	}
	return res;
}

int main(int argc, char* argv[])
{
	while (scanf("%d", &n) != EOF && n)
	{
		g_ecount = 0;
		memset(g_parent, -1, sizeof(g_parent));
		for (int i = 0; i < n - 1; ++i)
		{
			char s[10], t[10];
			int num, w;
			scanf("%s%d", s, &num);
			while (num--)
			{
				scanf("%s%d", t, &w);
				g_edge[g_ecount].u = s[0] - 'A';
				g_edge[g_ecount].v = t[0] - 'A';
				g_edge[g_ecount++].w = w;
			}
		}
		printf("%d\n", kruscal());
	}
	return 0;
}