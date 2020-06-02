#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define N 10005
struct Edge
{
    int to,next;
}e[100005];
int ec,n,pp[N],dfn[N],stack[N],low[N],index,top,cnt,res;
bool instack[N],vis[N];

void add(int u,int v)
{
    e[ec].to=v;
    e[ec].next=pp[u];
    pp[u]=ec++;
}

void dfs(int u)
{
    vis[u]=true;
    int i;
    for(i=pp[u];i!=-1;i=e[i].next)
    {
        if(!vis[e[i].to])
            dfs(e[i].to);
    }
}

bool check(int u)
{
    int i,j,k;
    memset(vis,0,sizeof(vis));
    dfs(u);
    for(i=1;i<=n;i++)
        if(!vis[i])
            return false;
    return true;
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
        else if(instack[v]&&dfn[v]<low[u])
            low[u]=dfn[v];
    }
    if(dfn[u]==low[u])
    {
        int temp=0;
        do{
            j=stack[top--];
            instack[j]=false;
            temp++;
        }while(j!=u);
        if(check(u))
            res+=temp;
    }
}

void solve()
{
    int i,j,k;
    index=cnt=top=0;
    memset(dfn,0,sizeof(dfn));
    memset(instack,0,sizeof(instack));
    for(i=1;i<=n;i++)
    {
        if(!dfn[i])
        {
            tarjan(i);
        }
    }
    printf("%d\n",res);
}

int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,k,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        ec=0;
        res=0;
        memset(pp,-1,sizeof(pp));
        while(m--)
        {
            scanf("%d%d",&i,&j);
            add(j,i);
        }
        solve();
    }
    //while(1);
    return 0;
}
