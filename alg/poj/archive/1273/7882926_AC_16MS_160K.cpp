#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define Inf 9999999
#define N 250
struct Edge
{
    int to,cap,next,opt;
}e[N*N];
int ec,pp[N],n,level[N],que[N],s,t;

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

bool makelevel()
{
    int i,j,k,head=0,tail=0;
    memset(level,-1,sizeof(level));
    que[tail++]=s;
    level[s]=0;
    while(head<tail)
    {
        k=que[head++];
        for(i=pp[k];i!=-1;i=e[i].next)
        {
            int v=e[i].to;
            if(e[i].cap>0&&level[v]==-1)
            {
                level[v]=level[k]+1;
                que[tail++]=v;
            }
        }
    }
    return level[t]!=-1;
}

int findpath(int alpha,int u)
{
    int i,j,k,w=0;
    if(u==t)
        return alpha;
    for(i=pp[u];i!=-1;i=e[i].next)
    {
        if(e[i].cap>0&&level[e[i].to]==level[u]+1)
        {
            if(k=findpath(min(e[i].cap,alpha-w),e[i].to))
            {
                e[i].cap-=k;
                e[e[i].opt].cap+=k;
                w+=k;
            }
        }
    }
    return w;
}

void solve()
{
    int i,j,k=0;
    while(makelevel())
        while(j=findpath(Inf,s))
            k+=j;
    printf("%d\n",k);
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
            add(i,j,k);
        }
        s=1,t=n;
        solve();
    }
    //while(1);
    return 0;
}
