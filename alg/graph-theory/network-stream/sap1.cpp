/*
sap算法求最大流,图用邻接矩阵表示 
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define N 10000
#define Inf 9999999
int G[N][N],n;//初始网络
int c[N][N];//残留网络
int dist[N],que[N],gap[2*N],pre[N];

void bfs(int t)//从汇点bfs求得层次图 
{
    int i,j,k,head=0,tail=0;
    memset(dist,0,sizeof(dist));
    memset(gap,0,sizeof(gap));
    gap[0]=1;
    que[tail++]=t;
    while(head<tail)
    {
        k=que[head++];
        for(i=1;i<=n;i++)
        {
            if(G[i][k]>0&&!dist[i]&&i!=t)
            {
                dist[i]=dist[k]+1;
                gap[dist[i]]++;
                que[tail++]=i;
            }
        }
    }
}

int sap(int s,int t)
{
    int i,j,k,flow=0,u=s,neck;
    bfs(t);
    while(dist[s]<n)
    {
        if(u==t)
        {
            int cc=Inf;
            j=t;i=pre[j];
            while(j!=s)
            {
                if(c[i][j]<cc)
                {
                    cc=c[i][j];
                    neck=i;
                }
                j=i;
                i=pre[j];
            }
            flow+=cc;
            j=t;
            i=pre[j];
            while(j!=s)
            {
                c[i][j]-=cc;
                c[j][i]+=cc;
                j=i;
                i=pre[j];
            }
            u=neck;
        }
        for(i=1;i<=n;i++)
            if(c[u][i]>0&&dist[u]==dist[i]+1)
                break;
        if(i<=n)
        {
            pre[i]=u;
            u=i;
        }
        else
        {
            if(--gap[dist[u]]==0)break;
            int tmp=n-1;
            for(i=1;i<=n;i++)
                if(c[u][i]>0&&dist[i]<tmp)
                    tmp=dist[i];
            dist[u]=tmp+1;
            gap[dist[u]]++;
            if(u!=s)u=pre[u];
        }
    }
    return flow;
}

int main()
{
}
