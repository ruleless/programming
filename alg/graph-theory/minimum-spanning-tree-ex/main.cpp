/*
最小度限制生成树 
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>
#include <string>
using namespace std;
#define N 25
#define Inf 99999999
int edge[N][N],n,lim,cnt,parent[N],ec,Min,cur,Max[N],que[N],pre[N];
set<int>Set[N];
set<int>::iterator it;
bool vis[N],used[N][N];
struct Edge
{
    int u,v,w;
}e[N*N];

void dfs(int u)
{
    vis[u]=true;
    Set[cnt].insert(u);
    for(int v=1;v<=n;v++)
        if(!vis[v]&&edge[u][v]<Inf)
            dfs(v);
}
void liantong()//求除去V0的图的连通块 
{
    memset(vis,0,sizeof(vis));
    cnt=0;
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            dfs(i);
            cnt++;
        }
}
int Find(int x)
{
    if(parent[x]<0)
        return x;
    int r=Find(parent[x]);
    parent[x]=r;
    return r;
}
void Union(int x,int y)
{
    int a=Find(x),b=Find(y);
    if(a==b)
        return;
    if(parent[a]<parent[b])
    {
        parent[a]+=parent[b];
        parent[b]=a;
    }
    else
    {
        parent[b]+=parent[a];
        parent[a]=b;
    }
}
int cmp(const void* a,const void* b)
{
    return ((struct Edge*)a)->w-((struct Edge*)b)->w;
}
void kruscal()//kruscal算法求外围最小生成树 
{
    int i,j,k;
    memset(used,0,sizeof(used));
    memset(parent,-1,sizeof(parent));
    qsort(e,ec,sizeof(struct Edge),cmp);
    cur=0;
    for(i=0;i<ec;i++)
    {
        if(Find(e[i].u)!=Find(e[i].v))
        {
            int a=e[i].u,b=e[i].v;
            cur+=e[i].w;
            used[a][b]=used[b][a]=true;
            Union(a,b);
        }
    }
}
void bfs()//求Max数组 
{
    int i,j,k,head=0,tail=0;
    memset(Max,0,sizeof(Max));
    que[tail++]=0;
    memset(vis,0,sizeof(vis));
    vis[0]=true;
    while(head<tail)
    {
        k=que[head++];
        for(i=1;i<=n;i++)
        {
            if(used[k][i]&&!vis[i])
            {
                pre[i]=k;
                que[tail++]=i;
                vis[i]=true;
                if(k!=0)
                {
                    Max[i]=max(Max[k],edge[k][i]);
                }
            }
        }
    }
}
int kernel()//算法核心 
{
    int i,j,k;
    liantong();
    kruscal();
    for(i=0;i<cnt;i++)
    {
        k=*Set[i].begin();
        for(it=Set[i].begin();it!=Set[i].end();it++)
        {
            if(edge[0][*it]<edge[0][k])
                k=*it;
        }
        used[0][k]=used[k][0]=true;
        cur+=edge[0][k];
    }
    Min=cur;
    bfs();
    for(k=cnt+1;k<=lim;k++)
    {
        int temp=Inf;
        for(i=1;i<=n;i++)
        {
            if(!used[0][i]&&edge[0][i]<Inf&&edge[0][i]-Max[i]<temp)
            {
                temp=edge[0][i]-Max[i];
                j=i;
            }
        }
        if(temp==Inf)break;
        for(i=j;edge[pre[i]][i]!=Max[j];i=pre[i]);
        used[pre[i]][i]=used[i][pre[i]]=false;
        used[0][j]=used[j][0]=true;
        cur+=(edge[0][j]-Max[j]);
        Min=min(Min,cur);
        bfs();
    }
    return Min;
}
int main()
{
}
