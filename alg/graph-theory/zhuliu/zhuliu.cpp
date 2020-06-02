/*
朱刘算法求最小树形图 
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define Inf 9999999
#define N 105
int cost[N][N],n,pre[N];
bool vis[N],flag[N];
void dfs(int u)
{
    vis[u]=true;
    for(int v=1;v<=n;v++)
        if(!vis[v]&&cost[u][v]<Inf)
            dfs(v);
}
bool check(int s)
{
    int i;
    memset(vis,0,sizeof(vis));
    dfs(s);
    for(i=1;i<=n;i++)
        if(!vis[i])
            return false;
    return true;
}
int zhuliu(int s)
{
    int i,j,k,res=0;
    memset(flag,0,sizeof(flag));
    while(true)
    {
        for(i=1;i<=n;i++)
        {
            if(i==s||flag[i])continue;
            cost[i][i]=Inf;
            pre[i]=i;
            for(k=1;k<=n;k++)
                if(!flag[k]&&cost[k][i]<cost[pre[i]][i])
                    pre[i]=k;
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
            res+=cost[pre[i]][i];
            for(j=pre[i];j!=i;j=pre[j])
            {
                flag[j]=true;
                res+=cost[pre[j]][j];
            }
            for(k=1;k<=n;k++)
                if(!flag[k]&&cost[k][i]<Inf)
                    cost[k][i]-=cost[pre[i]][i];
            for(j=pre[i];j!=i;j=pre[j])
            {
                for(k=1;k<=n;k++)
                    if(!flag[k])
                    {
                        cost[i][k]=min(cost[i][k],cost[j][k]);
                        cost[k][i]=min(cost[k][i],cost[k][j]-cost[pre[j]][j]);
                    }
            }
            break;
        }
        if(i==n+1)break;
    }
    for(i=1;i<=n;i++)
        if(i!=s&&!flag[i])
            res+=cost[pre[i]][i];
    return res;
}
int main()
{
}
