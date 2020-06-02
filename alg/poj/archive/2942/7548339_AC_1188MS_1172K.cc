#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <cstdlib>
using namespace std;
#define N 1020
set<int> Set[N];
set<int>::iterator it;

bool edge[N][N],inG[N],flag[N];
int n,dfn[N],low[N],stafrom[N*N],stato[N*N],top,index,cnt,color[N];

bool check(int,int);

void tarjan(int u,int p)
{
    int i,j,k,v;
    dfn[u]=low[u]=++index;
    for(v=1;v<=n;v++)
    {
        if(edge[u][v]&&v!=p&&dfn[v]<dfn[u])
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
                        i=stafrom[top];
                        j=stato[top--];
                        Set[cnt].insert(i);
                        Set[cnt].insert(j);
                    }while(! (i==u&&j==v) );
                    cnt++;
                }
            }
            else if(dfn[v]<low[u])
                low[u]=dfn[v];
        }
    }
}
void liantong()
{
    int i,j,k;
    top=cnt=index=0;
    memset(dfn,0,sizeof(dfn));
    for(i=1;i<=n;i++)
    {
        if(!dfn[i])
        {
            tarjan(i,0);
        }
    }
}
bool check(int u,int col)
{
    color[u]=col;
    for(int v=1;v<=n;v++)
    {
        if(edge[u][v]&&inG[v])
        {
            if(color[v]==-1)
            {
                int coll=(col?0:1);
                if(!check(v,coll))
                    return false;
            }
            else if(color[v]==color[u])
                return false;
        }
    }
    return true;
}
void solve()
{
    int i,j,k;
    memset(flag,0,sizeof(flag));
    liantong();
    memset(flag,0,sizeof(flag));
    for(i=0;i<cnt;i++)
    {
        if(Set[i].size()<3)
            continue;
        memset(inG,0,sizeof(inG));
        memset(color,-1,sizeof(color));
        for(it=Set[i].begin();it!=Set[i].end();it++)
        {
            inG[*it]=true;
        }
        j=*Set[i].begin();
        if(!check(j,0))
        {
            for(it=Set[i].begin();it!=Set[i].end();it++)
            {
                flag[*it]=true;
            }
        }
    }
    k=0;
    for(i=1;i<=n;i++)
        if(!flag[i])
            k++;
    printf("%d\n",k);
}

int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,k,m;
    while(scanf("%d%d",&n,&m)!=EOF&&n+m)
    {
        for(i=1;i<=n;i++)
        {
            edge[i][i]=false;
            for(j=i+1;j<=n;j++)
                edge[i][j]=edge[j][i]=true;
        }
        while(m--)
        {
            scanf("%d%d",&i,&j);
            edge[i][j]=edge[j][i]=false;
        }
        solve();
        for(i=0;i<cnt;i++)
            Set[i].clear();
    }
    //while(1);
    return 0;
}

