#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define Inf 999999999
#define N 215
struct Edge
{
    int u,v,w;
}e[40009];
int pp[N],ec,n,c[N][N],T;
int dist[N*2],gap[2*N],que[N*2],pre[N],low,high;
bool vis[N];

void bfs(int t)//从汇点bfs求得层次图 
{
    int i,j,k,head=0,tail=0;
    memset(dist,0,sizeof(dist));
    memset(gap,0,sizeof(gap));
    gap[0]=1;
    que[tail++]=t;
    while(head<tail)
    {
        k=que[head++];
        for(i=1;i<=n;i++)
        {
            if(c[i][k]>0&&!dist[i]&&i!=t)
            {
                dist[i]=dist[k]+1;
                gap[dist[i]]++;
                que[tail++]=i;
            }
        }
    }
}

bool sap(int s,int t)
{
    int i,j,k,flow=0,u=s,neck;
    bfs(t);
    while(dist[s]<n)
    {
        if(u==t)
        {
            int cc=Inf;
            j=t;i=pre[j];
            while(j!=s)
            {
                if(c[i][j]<cc)
                {
                    cc=c[i][j];
                    neck=i;
                }
                j=i;
                i=pre[j];
            }
            flow+=cc;
            j=t;
            i=pre[j];
            while(j!=s)
            {
                c[i][j]-=cc;
                c[j][i]+=cc;
                j=i;
                i=pre[j];
            }
            u=neck;
        }
        for(i=1;i<=n;i++)
            if(c[u][i]>0&&dist[u]==dist[i]+1)
                break;
        if(i<=n)
        {
            pre[i]=u;
            u=i;
        }
        else
        {
            if(--gap[dist[u]]==0)break;
            int tmp=n-1;
            for(i=1;i<=n;i++)
                if(c[u][i]>0&&dist[i]<tmp)
                    tmp=dist[i];
            dist[u]=tmp+1;
            gap[dist[u]]++;
            if(u!=s)u=pre[u];
        }
    }
    if(flow>=T)return true;
    return false;
}

void make(int mid)
{
    int i,j,k;
    memset(c,0,sizeof(c));
    for(i=0;i<ec;i++)
    {
        int x=e[i].u;
        int y=e[j].v;
        if(e[i].w<=mid)
        {
            c[i][j]++;
            c[j][i]++;
        }
    }
}
void solve(int s,int t)
{
    int i,j,k,mid;
    while(low<high)
    {
        mid=(low+high)/2;
        make(mid);
        if(sap(s,t))
        {
            high=mid;
        }
        else
            low=mid+1;
    }
    printf("%d\n",low);
}

int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,k,m;
    scanf("%d%d%d",&n,&m,&T);
    ec=0;
    low=Inf;
    high=0;
    memset(pp,-1,sizeof(pp));
    while(m--)
    {
        scanf("%d%d%d",&i,&j,&k);
        low=min(low,k);
        high=max(high,k);
        e[ec].u=i;
        e[ec].v=j;
        e[ec++].w=k;
    }
    //printf("%d %d\n",low,high);
    solve(1,n);
    //while(1);
    return 0;
}
