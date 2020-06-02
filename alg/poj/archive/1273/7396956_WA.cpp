#include <iostream>
#include <cstdio>

using namespace std;

#define MAX 9999999

struct Edge
{
    int to,cap,next,opt;
}e[500];
int ec,pp[205],n;

int dist[205],pre[205],low[205],gap[205],que[205],vis[205],cur[205];

void bfs(int t)
{
    int i,j,k;
    int head=0,tail=0;
    memset(vis,0,sizeof(vis));
    dist[t]=0;
    gap[0]=1;
    que[tail++]=t;
    vis[t]=true;
    while(head<tail)
    {
        k=que[head++];
        for(i=pp[k];i!=-1;i=e[i].next)
        {
            int v=e[i].to;
            if(!vis[v])
            {
                vis[v]=true;
                dist[v]=dist[k]+1;
                gap[dist[v]]++;
            }
        }
    }
}

int sap(int s,int t)
{
    int i,j,k,flow=0,u=s,v;
    bfs(t);
    memset(low,0,sizeof(low));
    for(i=1;i<=n;i++)
    {
        //printf("%d:%d\n",i,dist[i]);
    }
    while(dist[s]<n)
    {
        //printf("yes\n");
        low[s]=MAX;
        bool flag=false;
        for(i=pp[u];i!=-1;i=e[i].next)
        {
            v=e[i].to;
            if(e[i].cap>0&&dist[u]==dist[v]+1)
            {
                flag=true;
                break;
            }
        }
        if(flag)
        {
            low[v]=e[i].cap;
            if(low[u]<low[v])low[v]=low[u];
            cur[u]=i;
            pre[v]=u;
            u=v;
            if(u==t)
            {
                flow+=low[t];
                j=t;
                while(j!=s)
                {
                    k=pre[j];
                    e[cur[k]].cap-=low[t];
                    e[e[cur[k]].opt].cap+=low[t];
                    j=k;
                }
                u=s;
                memset(low,0,sizeof(low));
            }
        }
        else
        {
            int h=MAX;
            for(i=pp[u];i!=-1;i=e[i].next)
            {
                v=e[i].to;
                if(e[i].cap>0&&h>dist[v]+1)
                {
                    h=dist[v]+1;
                }
            }
            gap[dist[u]]--;
            //if(gap[dist[u]]==0)break;
            dist[u]=h;
            if(h<205)gap[h]++;
            if(u!=s)
            {
                u=pre[u];
            }
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
        ec=0;
        while(m--)
        {
            scanf("%d%d%d",&i,&j,&k);
            e[ec].to=j;
            e[ec].cap=k;
            e[ec].opt=ec+1;
            e[ec].next=pp[i];
            pp[i]=ec++;
            
            e[ec].to=i;
            e[ec].cap=0;
            e[ec].opt=ec-1;
            e[ec].next=pp[j];
            pp[j]=ec++;
        }
        printf("%d\n",sap(1,n));
    }
    //while(1);
    return 0;
}
