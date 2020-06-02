#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define N 1010
struct Node
{
    int x,y;
}node[N];
struct Edge
{
    int to,next;
}e[N*N];
int ec,pp[N],dfn[N],low[N],stack[N],index,top,cnt,belong[N],n;
bool instack[N];

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
    if(low[u]==dfn[u])
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
    top=index=cnt=0;
    memset(dfn,0,sizeof(dfn));
    for(i=0;i<2*n;i++)
        if(!dfn[i])
            tarjan(i);
    for(i=0;i<n;i++)
        if(belong[2*i]==belong[2*i+1])
            return false;
    return true;
}

bool is(struct Node a,struct Node b)
{
    if( ( min(a.x,a.y)<min(b.x,b.y)&&min(b.x,b.y)<max(a.x,a.y)&&max(a.x,a.y)<max(b.x,b.y) )||
    ( ( min(b.x,b.y)<min(a.x,a.y)&&min(a.x,a.y)<max(b.x,b.y)&&max(b.x,b.y)<max(a.x,a.y) ) ) )
        return true;
    return false;
}
inline void add(int u,int v)
{
    e[ec].to=v;
    e[ec].next=pp[u];
    pp[u]=ec++;
}

int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,k,m,a,b,aa,bb;
    while(scanf("%d%d",&m,&n)==2)
    {
        for(i=0;i<n;i++)
            scanf("%d%d",&node[i].x,&node[i].y);
        ec=0;
        memset(pp,-1,sizeof(pp));
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(is(node[i],node[j]))
                {
                    a=2*i;b=2*j;
                    aa=a+1;bb=b+1;
                    add(a,bb);add(b,aa);
                    
                    a=2*i+1;b=2*j+1;
                    aa=a-1;bb=b-1;
                    add(a,bb);add(b,aa);
                }
            }
        }
        if(check())
            printf("panda is telling the truth...\n");
        else
            printf("the evil panda is lying again\n");
    }
    //while(1);
    return 0;
}
