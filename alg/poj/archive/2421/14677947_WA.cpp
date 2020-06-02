#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 105
int edge[N][N], n, gMinEdge[N][N];

int prim(int s, int t)
{
        if (gMinEdge[s][t] != -1)
                return gMinEdge[s][t];

        bool bSets[N];
        int minEdge[N];
        for (int i = 1; i <= n; ++i)
        {
                minEdge[i] = edge[s][i];
                bSets[i] = false;
        }
        bSets[s] = true;

        for (int i = 1; i <= n-1; ++i)
        {
                int u = 1;
                while (bSets[u]) ++u;
                for (int j = u+1; j <= n; ++j)
                {
                        if (!bSets[j] && minEdge[j] < minEdge[u])
                                u = j;
                }

                gMinEdge[s][u] = minEdge[u];
                if (u == t)
                        return gMinEdge[s][u];

                bSets[u] = true;
                for (int v = 1; v <= n; ++v)
                {
                        if (!bSets[v] && edge[u][v] < minEdge[v])
                                minEdge[v] = edge[u][v];
                }
        }
        return -1;
}

int main(int argc, char *argv[])
{
        // freopen("in.txt", "r", stdin);
        memset(gMinEdge, -1, sizeof(gMinEdge));

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
                printf("%d\n", prim(s, t));
        }

        return 0;
}