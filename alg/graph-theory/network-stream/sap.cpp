#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define N 10000
#define Inf 99999999
struct Edge
{
    int to,cap,opt,next;
}e[100000];
int ec,pp[10000],n;//pp[i]用于保存第i个节点的边,n为图的节点数目
int que[N],dist[N],gap[2*N],pre[N],cur[N];

void bfs(int t)
{
    int i,j,k,head=0,tail=0;
    memset(dist,0,sizeof(dist));
    memset(gap,0,sizeof(gap));
    gap[0]=1;
    que[tail++]=t;
    while(head<tail)
    {
        k=que[head++];
        for(i=pp[k];i!=-1;i=e[i].next)
        {
            int v=e[i].to;
            if(!dist[v]&&v!=t)
            {
                dist[v]=dist[k]+1;
                gap[dist[v]]++;
                que[tail++]=v;
            }
        }
    }
}

int sap(int s,int t)
{
    int i,j,k,flow=0,u=s,neck;
    memcpy(cur,pp,sizeof(pp));
    bfs(t);
    while(dist[s]<n)
    {
        if(u==t)
        {
            int cc=Inf;
            for(i=s;i!=t;i=e[cur[i]].to)
                if(e[cur[i]].cap<cc)
                {
                    neck=i;
                    cc=e[cur[i]].cap;
                }
            flow+=cc;
            for(i=s;i!=t;i=e[cur[i]].to)
            {
                e[cur[i]].cap-=cc;
                e[e[cur[i]].opt].cap+=cc;
            }
            u=neck;
        }
        for(i=cur[u];i!=-1;i=e[i].next)
            if(e[i].cap>0&&dist[u]==dist[e[i].to]+1)
                break;
        if(i!=-1)
        {
            cur[u]=i;
            pre[e[i].to]=u;
            u=e[i].to;
        }
        else
        {
            if(--gap[dist[u]]==0)break;
            cur[u]=pp[u];
            int tmp=n-1;
            for(i=pp[u];i!=-1;i=e[i].next)
                if(e[i].cap>0&&dist[e[i].to]<tmp)
                    tmp=dist[e[i].to];
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
