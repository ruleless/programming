#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;
#define N 30
#define Inf 99999999
int n,cost[N+1][N+1],lim,cnt;
set<int> ss[105];
set<int>::iterator it;
bool vis[N],used[N][N];
int parent[N],Max[N],que[N],pre[N];
struct Edge
{
    int u,v,w;
}edge[N*N];
int ec;
int Min,curmst,closedge[N];
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
    if(a!=b)parent[a]=b;
}
int cmp(const void* a,const void* b)
{
    return ((struct Edge*)a)->w-((struct Edge*)b)->w;
}
void kru()
{
    int i,j,k;
    memset(parent,-1,sizeof(parent));
    qsort(edge,ec,sizeof(struct Edge),cmp);
    memset(used,0,sizeof(used));
    curmst=0;
    for(k=0;k<ec;k++)
    {
        i=edge[k].u;j=edge[k].v;
        if(Find(i)!=Find(j))
        {
            Union(i,j);
            curmst+=edge[k].w;
            used[i][j]=used[j][i]=true;
        }
    }
}
void dfs(int u)//求连通块 
{
    vis[u]=true;
    ss[cnt].insert(u);
    for(int v=1;v<=n;v++)
        if(!vis[v]&&cost[u][v]<Inf)
            dfs(v);
}
void solve()
{
    set<int>::iterator it;
    int i,j,k,head,tail;
    memset(vis,0,sizeof(vis));
    cnt=0;
    for(i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
            cnt++;
        }
    }
    kru();
    for(i=0;i<cnt;i++)
    {
        int temp=Inf;
        for(it=ss[i].begin();it!=ss[i].end();it++)
        {
            j=*it;
            if(cost[0][j]<temp)
            {
                temp=cost[0][j];
                k=j;
            }
        }
        used[k][0]=used[0][k]=true;
        curmst+=cost[0][k];
    }
    memset(Max,0,sizeof(Max));
    head=tail=0;
    memset(vis,0,sizeof(vis));
    que[tail++]=0;
    vis[0]=true;
    while(head<tail)
    {
        k=que[head++];
        for(i=1;i<=n;i++)
        {
            if(!vis[i]&&used[k][i])
            {
                pre[i]=k;
                que[tail++]=i;
                vis[i]=true;
                if(k!=0)
                {
                    Max[i]=max(Max[i],cost[k][i]);
                }
            }
        }
    }
    for(k=cnt+1;k<=lim;k++)
    {
        int temp=Inf;
        for(i=1;i<=n;i++)
        {
            if(cost[0][i]<Inf&&!used[0][i]&&cost[0][i]-Max[i]<temp)
            {
                temp=cost[0][i]-Max[i];j=i;
            }
        }
        if(temp==Inf)break;
        used[j][0]=used[0][j]=true;
        curmst+=cost[0][j]-Max[j];
        for(i=j;cost[pre[i]][i]!=Max[j];i=pre[i]);
        used[pre[i]][i]=false;
        used[i][pre[i]]=false;
        head=tail=0;
        memset(vis,0,sizeof(vis));
        que[tail++]=0;
        vis[0]=true;
        while(head<tail)
        {
            int u=que[head++];
            for(int v=1;v<=n;v++)
            {
                if(!vis[v]&&used[u][v])
                {
                    que[tail++]=v;
                    vis[v]=true;
                    pre[v]=u;
                    if(u!=0)
                        Max[v]=max(Max[v],cost[u][v]);
                }
            }
        }
    }
    printf("Total miles driven: %d\n",curmst);
}

int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,k,m;
    char name1[20],name2[20];
    n=0;
    for(i=0;i<=N;i++)
        for(j=0;j<=N;j++)
            cost[i][j]=Inf;
    map<string,int>Map;
    scanf("%d",&m);
    Map[string("Park")]=0;
    ec=0;
    while(m--)
    {
        scanf("%s %s%d",name1,name2,&k);
        if(Map.find(name1)==Map.end())Map[string(name1)]=++n;
        if(Map.find(name2)==Map.end())Map[string(name2)]=++n;
        i=Map[name1];j=Map[name2];
        cost[i][j]=cost[j][i]=k;
        if(i!=0&&j!=0)
        {
            edge[ec].u=i;
            edge[ec].v=j;
            edge[ec++].w=k;
        }
    }
    scanf("%d",&lim);
    /*for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
            printf("%d ",cost[i][j]);
        printf("\n");
    }*/
    solve();
    //while(1);
    return 0;
}
