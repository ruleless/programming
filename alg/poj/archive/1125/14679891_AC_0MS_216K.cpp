#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Inf 999999
#define N 105

void floyd(int edge[N][N], int n, int f[N][N])
{
        memcpy(f, edge, sizeof(int)*N*N);
        for (int k = 1; k <= n; ++k)
        {
                for (int u = 1; u <= n; ++u)
                {
                        for (int v = 1; v <= n; ++v)
                        {
                                if (f[u][k]+f[k][v] < f[u][v])
                                        f[u][v] = f[u][k]+f[k][v];
                        }
                }
        }
}

int main(int argc, char *argv[])
{
        // freopen("in.txt", "r", stdin);

        int edge[N][N], n = 0;
        int f[N][N];
        while (scanf("%d", &n) != EOF && n)
        {
                for (int u = 1; u <= n; ++u)
                {
                        for (int v = u; v <= n; ++v)
                        {
                                edge[u][v] = edge[v][u] = (u == v ? 0 : Inf);
                        }
                }
                for (int u = 1; u <= n; ++u)
                {
                        int cnt;
                        scanf("%d", &cnt);
                        while (cnt--)
                        {
                                int v, w;
                                scanf("%d%d", &v, &w);
                                edge[u][v] = w;
                        }
                }

                floyd(edge, n, f);
                int s = -1, w = Inf;
                for (int u = 1; u <= n; ++u)
                {
                        int maxW = 0;
                        for (int v = 1; v <= n; ++v)
                        {
                                if (f[u][v] > maxW)
                                        maxW = f[u][v];
                        }

                        if (maxW < w)
                        {
                                w = maxW;
                                s = u;
                        }
                }
                if (s != -1)
                        printf("%d %d\n", s, w);
                else
                        printf("disjoint\n");
        }
        return (0);
}
