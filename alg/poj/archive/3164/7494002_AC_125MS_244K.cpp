#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;
#define N 105
#define Inf 10e30
double w[N][N];
bool vis[N],flag[N];
int n,pre[N];
struct Point
{
    int x,y;
}p[N];
double dis(struct Point a,struct Point b)
{
    return sqrt( (a.x-b.x)*(a.x-b.x)*1.0+(a.y-b.y)*(a.y-b.y)*1.0 );
}
void dfs(int u)
{
    vis[u]=true;
    for(int v=1;v<=n;v++)
        if(!vis[v]&&w[u][v]<Inf)
            dfs(v);
}
bool check()
{
    int i,j,k;
    memset(vis,0,sizeof(vis));
    dfs(1);
    for(i=1;i<=n;i++)
        if(vis[i]==false)
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
            w[i][i]=Inf;pre[i]=i;
            for(j=1;j<=n;j++)
                if(!flag[j]&&w[j][i]<w[pre[i]][i])
                    pre[i]=j;
        }
        for(i=1;i<=n;i++)
        {
            if(i==s||flag[i])continue;
            memset(vis,0,sizeof(vis));
            vis[s]=true;
            j=i;
            do{
                vis[j]=true;j=pre[j];
            }while(vis[j]==false);
            if(j==s)continue;
            i=j;
            res+=w[pre[i]][i];
            for(j=pre[i];j!=i;j=pre[j])
            {
                res+=w[pre[j]][j];
                flag[j]=true;
            }
            for(k=1;k<=n;k++)
            {
                if(!flag[k]&&w[k][i]<Inf)
                    w[k][i]-=w[pre[i]][i];
            }
            for(k=1;k<=n;k++)
            {
                if(!flag[k])
                {
                    for(j=pre[i];j!=i;j=pre[j])
                    {
                        w[i][k]=min(w[i][k],w[j][k]);
                        if(w[k][j]<Inf)w[k][i]=min(w[k][i],w[k][j]-w[pre[j]][j]);
                    }
                }
            }
            break;
        }
        if(i==n+1)break;
    }
    for(i=1;i<=n;i++)
        if(i!=s&&!flag[i])
            res+=w[pre[i]][i];
    return res;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,k,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%d%d",&p[i].x,&p[i].y);
        for(i=1;i<=n;i++)
            for(j=i;j<=n;j++)
                w[i][j]=w[j][i]=Inf;
        while(m--)
        {
            scanf("%d%d",&i,&j);
            w[i][j]=dis(p[i],p[j]);
        }
        if(!check())
            printf("poor snoopy\n");
        else
            printf("%.2lf\n",zhuliu(1));
    }
    //while(1);
    return 0;
}
