#include <iostream>
#include <cstdio>

using namespace std;

struct Edge
{
    int to,cap,opt,next;
}e[100000];
int ec,pp[105],n;

int dist[105],gap[2*105],cur[105],que[105],pre[105];

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
            if(!dist[e[i].to]&&e[i].to!=t)
            {
                dist[e[i].to]=dist[k]+1;
                gap[dist[e[i].to]]++;
                que[tail++]=e[i].to;
            }
        }
    }
}

#define MAX 90000000

int sap(int s,int t)
{
    int i,j,k,flow=0,u=s,neck;
    //bfs(t);
    gap[0]=n+1;
    for(i=0;i<=n+1;i++)
    {
        cur[i]=pp[i];
    }
    while(dist[s]<n+2)
    {
        if(u==t)
        {
            int cc=MAX;
            for(i=s;i!=t;i=e[cur[i]].to)
            {
                if(e[cur[i]].cap<cc)
                {
                    cc=e[cur[i]].cap;
                    neck=i;
                }
            }
            flow+=cc;
            for(i=s;i!=t;i=e[cur[i]].to)
            {
                e[cur[i]].cap-=cc;
                //e[e[cur[i]].opt].cap+=cc;
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
            int tmp=n+1;
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

inline void add(int u,int v,int cap,int ucap)
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
    int i,j,k,np,nc,m;
    while(scanf("%d%d%d%d",&n,&np,&nc,&m)!=EOF)
    {
        ec=0;
        memset(pp,-1,sizeof(pp));
        while(m--)
        {
            scanf(" (%d,%d)%d ",&i,&j,&k);
            i++,j++;
            add(i,j,k,0);
        }
        while(np--)
        {
            scanf(" (%d)%d ",&i,&k);
            i++;add(0,i,k,0);
        }
        while(nc--)
        {
            scanf(" (%d)%d ",&i,&k);
            i++;add(i,n+1,k,0);
        }
        /*for(i=0;i<=n+1;i++)
        {
            printf("%d: ",i);
            for(j=pp[i];j!=-1;j=e[j].next)
            {
                printf("%d(%d) ",e[j].to,e[j].cap);
            }
            printf("\n");
        }*/
        printf("%d\n",sap(0,n+1));
    }
    //while(1);
    return 0;
}
