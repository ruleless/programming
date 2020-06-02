/*
tarjan算法求强联通分量 
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

#define N 1000
struct Edge
{
    int to,next;
}e[100000];
int ec,pp[N],n;
int dfn[N],low[N],stack[N],index,top,cnt;
bool instack[N];
set<int>Set[N];

void tarjan(int u)
{
    int i,j,k,v;
    dfn[u]=low[u]=++index;
    stack[++top]=u;
    instack[u]=true;
    for(i=pp[u];i!=-1;i=e[i].next)
    {
        v=e[i].to;
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
        do{
            j=stack[top--];
            instack[j]=false;
            Set[cnt].insert(j);
        }while(j!=u);
        cnt++;
    }
}

void solve()
{
    int i,j,k;
    top=index=cnt=0;
    memset(instack,0,sizeof(instack));
    memset(dfn,0,sizeof(dfn));
    for(i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);
}

int main()
{
}
