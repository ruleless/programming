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

struct SNode
{
        int v[N];
        int n;

        SNode()
        {
                memset(v, 0, sizeof(v));
                n = 0;
        }
}gNode[N];
int gNodeCnt = 0;

int gEdge[N][N], n;
void genNode(int s, bool bInGraph[])
{
        bInGraph[s] = true;
        gNode[gNodeCnt].v[gNode[gNodeCnt].n++] = s;
        for (int v = s+1; v <= n; ++v)
        {
                if (!bInGraph[v] && gEdge[s][v] >= 0)
                {
                        genNode(v, bInGraph);
                }
        }
}

int distArr[N][N];
int resolve()
{
        bool bInGraph[N];
        memset(bInGraph, 0, sizeof(bInGraph));
        for (int i = 1; i <= n; ++i)
        {
                if (!bInGraph[i])
                {
                        genNode(i, bInGraph);
                        ++gNodeCnt;
                }
        }

        int edge[N][N];
        memset(edge, -1, sizeof(edge));
        for (int u = 1; u <= gNodeCnt; ++u)
        {
                edge[u][u] = 0;
                for (int v = u+1; v <= gNodeCnt; ++v)
                {
                        int dist = 99999999;
                        for (int i = 0; i < gNode[u-1].n; ++i)
                        {
                                int uu = gNode[u-1].v[i];
                                for (int j = 0; j < gNode[v-1].n; ++j)
                                {
                                        int vv = gNode[v-1].v[j];
                                        if (dist < 0 || distArr[uu][vv] < dist)
                                                dist = distArr[uu][vv];
                                }
                        }
                        edge[u][v] = edge[v][u] = dist;
                }
        }

        // for (int i = 0; i <= gNodeCnt; ++i)
        // {
        //      for (int j = 0; j < gNode[i].n; ++j)
        //      {
        //              printf("%d ", gNode[i].v[j]);
        //      }
        //      printf("\n");
        // }

        // printf("%d\n", gNodeCnt);
        // for (int i = 1; i <= gNodeCnt; ++i)
        // {
        //      for (int j = 1; j <= gNodeCnt; ++j)
        //      {
        //              printf("%d ", edge[i][j]);
        //      }
        //      printf("\n");
        // }

        return prim(edge, gNodeCnt);
}

int main(int argc, char *argv[])
{
        //freopen("in.txt", "r", stdin);

        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
                for (int j = 1; j <= n; ++j)
                {
                        scanf("%d", &distArr[i][j]);
                }
        }

        for (int i = 1; i <= n; ++i)
        {
                for (int j = 1; j <= n; ++j)
                {
                        gEdge[i][j] = (i == j ? 0 : -1);
                }
        }
        int Q;
        scanf("%d", &Q);
        while (Q--)
        {
                int s, t;
                scanf("%d%d", &s, &t);
                gEdge[s][t] = gEdge[t][s] = distArr[s][t];
        }

        printf("%d\n", resolve());

        return 0;
}