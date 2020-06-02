#include <iostream>
#include <cstdio>

using namespace std;
#define MAX 9999999

struct Edge
{
    int to,cap,opt,next;
}e[500006];
int ec,pp[20006],n;

int dist[20006],gap[20006],pre[20006],cur[20006],que[20006],low[20006];

void bfs(int t)
{
    int i,j,k,head=0,tail=0;
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
                que[tail++]=v;
                gap[dist[v]]++;
            }
        }
    }
}

int sap(int s,int t)
{
    int i,j,k,flow=0,u=s,v;
    bfs(t);
    while(dist[s]<n+2)
    {
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
            pre[v]=u;cur[u]=i;
            u=v;
            if(u==t)
            {
                j=t;
                flow+=low[t];
                while(j!=s)
                {
                    k=pre[j];
                    e[cur[k]].cap-=low[t];
                    //e[e[cur[k]].opt].cap+=low[t];
                    j=k;
                }
                u=s;
            }
        }
        else
        {
            if(!--gap[dist[u]])break;
            int h=MAX;
            for(i=pp[u];i!=-1;i=e[i].next)
            {
                if(e[i].cap>0&&dist[e[i].to]+1<h)
                {
                    h=dist[e[i].to]+1;
                }
            }
            if(h==MAX)
            {
                break;
            }
            dist[u]=h;
            gap[h]++;
            if(u!=s)u=pre[u];
        }
    }
    return flow;
}

void add(int u,int v,int cap,int ucap)
{
    e[ec].to=v;
    e[ec].cap=cap;
    e[ec].opt=ec+1;
    e[ec].next=pp[u];
    pp[u]=ec++;
    e[ec].to=u;
    e[ec].cap=ucap;
    e[ec].opt=ec-1;
    e[ec].next=pp[v];
    pp[v]=ec++;
}

int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,k,m,u;
    scanf("%d%d",&n,&m);
    memset(pp,-1,sizeof(pp));
    ec=0;
    for(u=1;u<=n;u++)
    {
        scanf("%d%d",&i,&j);
        add(0,u,i,0);
        add(u,n+1,j,0);
    }
    while(m--)
    {
        scanf("%d%d%d",&i,&j,&k);
        add(i,j,k,k);
    }
    /*for(i=0;i<=n+1;i++)
    {
        printf("%d: ",i);
        for(j=pp[i];j!=-1;j=e[j].next)
        {
            printf("%d (%d)",e[j].to,e[j].cap);
        }
        printf("\n");
    }*/
    printf("%d\n",sap(0,n+1));
   // while(1);
    return 0;
}
