#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 105
int gEdge[N][N], gNodeCnt;

int dijkstra(int edge[N][N], int n, int s, int t)
{
        bool bSets[N];
        int dist[N];

        memset(bSets, 0, sizeof(bSets));
        for (int i = 1; i <= n; ++i)
        {
                dist[i] = edge[s][i];
        }
        bSets[s] = true;
        dist[s] = 0;

        for (int i = 0; i < n-2; ++i)
        {
                int u = 1;
                while (bSets[u]) ++u;
                for (int j = u+1; j <=n ; ++j)
                {
                        if (!bSets[j] && dist[j] >= 0 && dist[j] < dist[u])
                                u = j;
                }
                bSets[u] = true;
                if (u == t)
                        return dist[u];
                for (int v = 1; v <= n; ++v)
                {
                        if (!bSets[v] && edge[u][v] >= 0 && dist[u]+edge[u][v] <                                                                                                                                                              dist[v])
                                dist[v] = dist[u]+edge[u][v];
                }
        }
        return dist[t];
}

int main(int argc, char *argv[])
{
        memset(gEdge, -1, sizeof(gEdge));
        gNodeCnt = 0;

        int s, t;
        scanf("%d%d%d", &gNodeCnt, &s, &t);
        for (int i = 1; i <= gNodeCnt; ++i)
        {
                int k = 0;
                scanf("%d", &k);
                for (int j = 0; j < k; ++j)
                {
                        int to = 0;
                        scanf("%d", &to);
                        if (0 == j)
                        {
                                gEdge[i][to] = 0;
                        }
                        else
                        {
                                gEdge[i][to] = 1;
                        }
                }
        }

        printf("%d\n", dijkstra(gEdge, gNodeCnt, s, t));

        return 0;
}