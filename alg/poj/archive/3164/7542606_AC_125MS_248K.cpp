#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
#define N 106
#define Inf 10e16
double cost[N][N];
bool vis[N],flag[N];
int n,pre[N];
struct Point
{
    int x,y;
}p[N];
double dist(struct Point a,struct Point b)
{
    return sqrt( (a.x-b.x)*(a.x-b.x)*1.0+(a.y-b.y)*(a.y-b.y)*1.0 );
}
void dfs(int u)
{
    int v;
    vis[u]=true;
    for(v=1;v<=n;v++)
    {
        if(!vis[v]&&cost[u][v]<Inf)
            dfs(v);
    }
}
bool check(int s)
{
    int i,j,k;
    memset(vis,0,sizeof(vis));
    dfs(s);
    for(i=1;i<=n;i++)
        if(!vis[i])
            return false;
    return true;
}
double zhuliu(int s)
{
    int i,j,k;
    double res=0;
    memset(flag,0,sizeof(flag));
    while(true)
    {
        for(i=1;i<=n;i++)
        {
            if(i==s||flag[i])continue;
            cost[i][i]=Inf;
            pre[i]=i;
            for(k=1;k<=n;k++)
            {
                if(!flag[k]&&cost[k][i]<cost[pre[i]][i])
                {
                    pre[i]=k;
                }
            }
        }
        /*for(i=1;i<=n;i++)
        {
            printf("%d\n",pre[i]);
        }
        while(1);*/
        for(i=1;i<=n;i++)
        {
            if(i==s||flag[i])continue;
            memset(vis,0,sizeof(vis));
            vis[s]=true;
            j=i;
            do{
                vis[j]=true;
                j=pre[j];
            }while(vis[j]==false);
            if(j==s)continue;
            i=j;
            res+=cost[pre[i]][i];
            for(j=pre[i];j!=i;j=pre[j])
            {
                flag[j]=true;
                res+=cost[pre[j]][j];
            }
            for(k=1;k<=n;k++)
            {
                if(!flag[k]&&cost[k][i]<Inf)
                    cost[k][i]-=cost[pre[i]][i];
            }
            for(j=pre[i];j!=i;j=pre[j])
            {
                for(k=1;k<=n;k++)
                {
                    if(!flag[k])
                    {
                        cost[i][k]=min(cost[i][k],cost[j][k]);
                        cost[k][i]=min(cost[k][i],cost[k][j]-cost[pre[j]][j]);
                    }
                }
            }
            break;
        }
        if(i==n+1)break;
    }
    for(i=1;i<=n;i++)
    {
        if(i!=s&&!flag[i])res+=cost[pre[i]][i];
    }
    return res;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,k,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                cost[i][j]=Inf;
        for(i=1;i<=n;i++)
            scanf("%d%d",&p[i].x,&p[i].y);
        while(m--)
        {
            scanf("%d%d",&i,&j);
            cost[i][j]=dist(p[i],p[j]);
        }
        if(!check(1))
            printf("poor snoopy\n");
        else
        {
            printf("%.2lf\n",zhuliu(1));
        }
    }
    //while(1);
    return 0;
}
