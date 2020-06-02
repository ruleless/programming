#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define N 5000
struct Edge
{
    int to,next;
}e[N*N];
int ec,pp[N],n,dfn[N],low[N],stack[N],belong[N],top,cnt,index,m;
bool instack[N];
struct Node
{
    int x,y;
}noden[N],nodem[N];
void build(int mid);

inline void add(int u,int v)
{
    e[ec].to=v;
    e[ec].next=pp[u];
    pp[u]=ec++;
}

void tarjan(int u)
{
    int i,j,k;
    dfn[u]=low[u]=++index;
    stack[++top]=u;
    instack[u]=true;
    for(i=pp[u];i!=-1;i=e[i].next)
    {
        int v=e[i].to;
        if(!dfn[v])
        {
            tarjan(v);
            if(low[v]<low[u])
                low[u]=low[v];
        }
        else if(dfn[v]<low[u]&&instack[v])
            low[u]=dfn[v];
    }
    if(dfn[u]==low[u])
    {
        do{
            j=stack[top--];
            instack[j]=false;
            belong[j]=cnt;
        }while(j!=u);
        cnt++;
    }
}
bool check()
{
    int i,j,k;
    cnt=top=index=0;
    memset(dfn,0,sizeof(dfn));
    memset(instack,0,sizeof(instack));
    for(i=0;i<2*n;i++)
        if(!dfn[i])
            tarjan(i);
    for(i=0;i<n;i++)
        if(belong[2*i]==belong[2*i+1])
            return false;
    return true;
}

void solve()
{
    int i,j,k,low=0,high=m,mid;
    while(low<high)
    {
        mid=(low+high)/2;
        build(mid);
        if(check())
            low=mid;
        else
            high=mid-1;
    }
    printf("%d\n",low);
}

void build(int mid)
{
    int i,j,k,a,b,aa,bb;
    ec=0;
    memset(pp,-1,sizeof(pp));
    for(i=0;i<n/2;i++)
    {
        a=noden[i].x*2+1;b=noden[i].y*2+1;
        aa=a-1;bb=b-1;
        add(a,bb);add(b,aa);
    }
    for(i=0;i<mid;i++)
    {
        a=nodem[i].x*2;b=nodem[i].y*2;
        aa=a+1;bb=b+1;
        add(a,bb);add(b,aa);
    }
}

int main()
{
   // freopen("in.txt","r",stdin);
    int i,j,k;
    while(scanf("%d%d",&n,&m)==2&&n==0&&m==0)
    {
        for(i=0;i<n;i++)
            scanf("%d%d",&noden[i].x,&noden[i].y);
        n*=2;
        for(i=0;i<m;i++)
            scanf("%d%d",&nodem[i].x,&nodem[i].y);
        solve();
        //build(5);
        //printf("%d\n",check());
    }
    //while(1);
    return 0;
}

