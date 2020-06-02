#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define Inf 99999999
#define N 520
int dist[N],n;
struct Edge
{
    int to,w,next;
}e[10000];
int ec,pp[N],que[1000000],intime[N];

inline void add(int u,int v,int w)
{
    e[ec].to=v;
    e[ec].w=w;
    e[ec].next=pp[u];
    pp[u]=ec++;
}
bool inque[N];

bool spfa(int s)
{
    int i,j,k,head=0,tail=0;
    memset(intime,0,sizeof(int)*(n+1));
    for(i=1;i<=n;i++)
        dist[i]=Inf;
    memset(inque,0,sizeof(inque));
    dist[s]=0;
    que[tail++]=s;
    inque[s]=true;
    while(head<tail)
    {
        k=que[head++];
        intime[k]++;
        if(intime[k]>n)
            return true;
        inque[k]=false;
        for(i=pp[k];i!=-1;i=e[i].next)
            if(dist[k]+e[i].w<dist[e[i].to])
            {
                dist[e[i].to]=dist[k]+e[i].w;
                if(!inque[e[i].to])
                {
                    que[tail++]=e[i].to;
                    inque[e[i].to]=true;
                }
            }
    }
    return false;
}

int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,k,t,m,w;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&w);
        ec=0;
        memset(pp,-1,sizeof(pp));
        while(m--)
        {
            scanf("%d%d%d",&i,&j,&k);
            add(i,j,k);
            add(j,i,k);
        }
        while(w--)
        {
            scanf("%d%d%d",&i,&j,&k);
            add(i,j,-k);
        }
        if(spfa(1))
            printf("YES\n");
        else
            printf("NO\n");
    }
    //while(1);
    return 0;
}
