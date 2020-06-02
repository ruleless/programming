#include<iostream>
#include<queue>
using namespace std;
int n, m, kind;
int s, t;
int order[51][51];
int store[51][51];
int cost[51][51][51];
int c[102][102];
int f[102][102];
int b[102][102];
int p[102];
int d[102];
bool visit[102]; //表示spfa中点是否在队列中
void spfa() //求Gf的最短路
{
    queue<int> q;
    memset(visit, 0, sizeof(visit));
    q.push(s);
    visit[s] = true;
    while(!q.empty())
    {
        int u = q.front();
        visit[u] = false;
        q.pop();
        for(int v=0; v<=n+m+1; v++)
            if(c[u][v] > f[u][v] && d[v] > d[u] + b[u][v])
            {
                d[v] = d[u] + b[u][v];
                p[v] = u;
                if(!visit[v])
                {
                    q.push(v);
                    visit[v] = true;
                }
            }
    }
}
void mcmf()
{
    while(1)
    {
        memset(p, -1, sizeof(p));
        for(int i=1; i<=n+m+1; i++)
            d[i] = 100000;
        d[s] = 0;
        spfa();
        if(p[t] == -1) //表示已无增广路
            break;
        int minf = INT_MAX;
        int it = t;
        while(p[it] != -1)
        {
            minf = min(minf, c[p[it]][it] - f[p[it]][it]);
            it = p[it];
        }
        it = t;
        while(p[it] != -1)
        {
            f[p[it]][it] += minf;
            f[it][p[it]] = -f[p[it]][it];
            it = p[it];
        }
    }
}
int main()
{
    while(1)
    {
       scanf("%d%d%d", &n, &m, &kind);
        if(n==0 && m==0 && kind==0)
           break;
       for(int i=1; i<=n; i++)
            for(int j=1; j<=kind; j++)
                scanf("%d", &order[i][j]);
        for(int i=1; i<=m; i++)
             for(int j=1; j<=kind; j++)
                 scanf("%d", &store[i][j]);
         for(int i=1; i<=kind; i++)
             for(int j=1; j<=n; j++)
                 for(int k=1; k<=m; k++)
                     scanf("%d", &cost[i][k][j]);
         s = 0; t = m+n+1;
         int res = 0;
         bool flag = true;
         for(int i=1; i<=kind; i++)
         {
             memset(c, 0, sizeof(c));
             for(int j=1; j<=m; j++)
                 c[s][j] = store[j][i];
             for(int j=1; j<=m; j++)
                 for(int k=1; k<=n; k++)
                     c[j][k+m] = store[j][i];
             for(int j=1; j<=n; j++)
                 c[j+m][t] = order[j][i];
             memset(b, 0, sizeof(b));
             for(int j=1; j<=m; j++)
                 for(int k=1; k<=n; k++)
                 {
                    b[j][k+m] = cost[i][j][k];
                    b[k+m][j] = -b[j][k+m]; //负费用，表示回流会减小费用
                }
            memset(f, 0, sizeof(f));
            mcmf();
            for(int j=1; j<=n; j++)
                if(c[j+m][t] != f[j+m][t])
                {
                    flag = false;
                    break;
                }
            if(!flag) break;
            for(int j=1; j<=m; j++)
                for(int k=1; k<=n; k++)
                    res += f[j][m+k] * b[j][m+k];
        }
        if(flag)
            printf("%d\n", res);
        else
            printf("-1\n");
    }
    return 0;
}