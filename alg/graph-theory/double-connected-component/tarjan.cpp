/*
tarjan算法求点双连通分量 
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;
#define N 10000
struct Edge
{
    int to,next;
}e[100000];
int ec,pp[N],n;
int dfn[N],low[N],stafrom[100000],stato[100000],top,index,cnt;
set<int>Set[N];

void tarjan(int u,int p)
{
    int i,j,k,v,x,y;
    dfn[u]=low[u]=++index;
    for(i=pp[u];i!=-1;i=e[i].next)
    {
        v=e[i].to;
        if(p!=v&&dfn[v]<dfn[u])
        {
            stafrom[++top]=u;
            stato[top]=v;
            if(!dfn[v])
            {
                tarjan(v,u);
                if(low[v]<low[u])
                    low[u]=low[v];
                if(dfn[u]<=low[v])
                {
                    do{
                        x=stafrom[top];
                        y=stato[top--];
                        Set[cnt].insert(x);
                        Set[cnt].insert(y);
                    }while( !(x==u&&y==v) );
                    cnt++;
                }
            }
            else if(dfn[v]<low[u])
                low[u]=dfn[v];
        }
    }
}

void solve()
{
    int i,j,k;
    index=top=cnt=0;
    memset(dfn,0,sizeof(dfn));
    for(i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i,-1);
}

int main()
{
}
