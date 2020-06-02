#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define Inf 9999999
#define N 300
struct Edge
{
    int to,cap,next,opt;
}e[N*N];
int ec,pp[N],n,pre[N],cur[N],que[N],dist[N],gap[N];
bool vis[N];

void add(int u,int v,int cap)
{
    e[ec].to=v;
    e[ec].cap=cap;
    e[ec].next=pp[u];
    e[ec].opt=ec+1;
    pp[u]=ec++;
    e[ec].to=u;
    e[ec].cap=0;
    e[ec].next=pp[v];
    e[ec].opt=ec-1;
    pp[v]=ec++;
}

void bfs(int t)
{
    int i,j,k,head=0,tail=0;
    memset(vis,0,sizeof(vis));
    memset(gap,0,sizeof(gap));
    que[tail++]=t;
    vis[t]=true;
    dist[t]=0;gap[0]++;
    while(head<tail)
    {
        k=que[head++];
        for(i=pp[k];i!=-1;i=e[i].next)
        {
            int v=e[i].to;
            if(!vis[v])
            {
                que[tail++]=v;
                vis[v]=true;
                dist[v]=dist[k]+1;
                gap[dist[v]]++;
            }
        }
    }
}

int sap(int s,int t)
{
    int i,j,k,u=s,flow=0,neck;
    memcpy(cur,pp,sizeof(pp));
    bfs(t);
    //printf("yes\n");
    while(dist[s]<n)
    {
        if(u==t)
        {
            int temp=Inf;
            for(i=s;i!=t;i=e[cur[i]].to)
            {
                if(e[cur[i]].cap<temp)
                {
                    temp=e[cur[i]].cap;
                    neck=i;
                }
            }
            flow+=temp;
            for(i=s;i!=t;i=e[cur[i]].to)
            {
                e[cur[i]].cap-=temp;
                e[e[cur[i]].opt].cap+=temp;
            }
            u=neck;
        }
        for(i=cur[u];i!=-1;i=e[i].next)
            if(e[i].cap>0&&dist[u]==dist[e[i].to]+1)
                break;
        if(i!=-1)
        {
            pre[e[i].to]=u;
            cur[u]=i;
            u=e[i].to;
        }
        else
        {
            if(!--gap[dist[u]])break;
            cur[u]=pp[u];
            int temp=n-1;
            for(i=pp[u];i!=-1;i=e[i].next)
                if(e[i].cap>0&&dist[e[i].to]<temp)
                    temp=dist[e[i].to];
            dist[u]=temp+1;
            gap[dist[u]]++;
            if(u!=s)u=pre[u];
        }
    }
    return flow;
}

int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,k,m;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        memset(pp,-1,sizeof(pp));
        while(m--)
        {
            scanf("%d%d%d",&i,&j,&k);
            add(i,j,k);
        }
        printf("%d\n",sap(1,n));
    }
    //while(1);
    return 0;
}
