#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Inf 9999999
#define N 505
int Graph[N][N], gNodeCnt;

bool bellman_ford(int edge[N][N], int n, int s, int dist[])
{
        for (int u=1; u <= n; ++u)
                dist[u] = Inf;
        dist[s] = 0;

        for (int k = 1; k <= n-1; ++k)
        {
                bool flag = true;
                for (int u = 1; u <= n; ++u)
                {
                        for (int v = 1; v <= n; ++v)
                        {
                                if (edge[u][v] < Inf && dist[u]+edge[u][v] < dist[v])
                                {
                                        dist[v] = dist[u]+edge[u][v];
                                        flag = false;
                                }
                        }
                }

                if (flag)
                        return true;
        }
        for (int u = 1; u <= n; ++u)
        {
                for (int v = 1; v <= n; ++v)
                {
                        if (edge[u][v] < Inf && dist[u]+edge[u][v] < dist[v])
                                return false;
                }
        }
        return true;
}

int main()
{
        // freopen("in.txt", "r", stdin);

        int F;
        scanf("%d", &F);
        while (F--)
        {
                int M, W;
                scanf("%d%d%d", &gNodeCnt, &M, &W);

                for (int i = 1; i <= gNodeCnt; ++i)
                {
                        for (int j = i; j <= gNodeCnt; ++j)
                        {
                                Graph[i][j] = Graph[j][i] = (i == j ? 0 : Inf);
                        }
                }
                while (M--)
                {
                        int s, t, w;
                        scanf("%d%d%d", &s, &t, &w);
                        if (w < Graph[s][t])
                        {
                                Graph[t][s] = w;
                                Graph[s][t] = w;
                        }
                }
                while (W--)
                {
                        int s, t, w;
                        scanf("%d%d%d", &s, &t, &w);
                        w = -w;
                        if (w < Graph[s][t])
                                Graph[s][t] = w;
                }

                int dist[N];
                if (bellman_ford(Graph, gNodeCnt, 1, dist))
                        printf("NO\n");
                else
                        printf("YES\n");
        }
        return 0;
}