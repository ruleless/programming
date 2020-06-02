#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define Inf 99999999
#define N 205
struct Edge
{
    int to,w,next;
}e[100000];
int pp[N],ec,n,c[N][N],T;
int dist[N],gap[2*N],que[N],pre[N],low,high;
bool vis[N];

void bfs(int t)
{
    int i,j,k,head=0,tail=0;
    memset(vis,0,sizeof(vis));
    memset(dist,0,sizeof(dist));
    vis[t]=true;
    que[tail++]=t;
    while(head<tail)
    {
        k=que[head++];
        for(i=1;i<=n;i++)
        {
            if(c[i][k]>0&&!vis[i])
            {
                que[tail++]=i;
                vis[i]=true;
                dist[i]=dist[k]+1;
            }
        }
    }
}

bool sap(int s,int t)
{
    int i,j,k,u=s,neck,flow=0;
    bfs(t);
    while(dist[s]<n)
    {
        if(u==t)
        {
            int temp=Inf;
            j=t;
            i=pre[j];
            while(j!=s)
            {
                if(c[i][j]<temp)
                {
                    neck=i;
                    temp=c[i][j];
                }
                j=i;
                i=pre[j];
            }
            flow+=temp;
            j=t;
            i=pre[j];
            while(j!=s)
            {
                c[i][j]+=temp;
                c[j][i]-=temp;
                j=i;
                i=pre[j];
            }
            u=neck;
        }
        for(i=1;i<=n;i++)
            if(c[u][i]>0&&dist[i]+1==dist[u])
                break;
        if(i!=n+1)
        {
            pre[i]=u;
            u=i;
        }
        else
        {
            if(--gap[dist[u]]==0)break;
            int temp=n-1;
            for(i=1;i<=n;i++)
            {
                if(c[u][i]>0&&dist[i]<temp)
                    temp=dist[i];
            }
            dist[u]=temp+1;
            gap[dist[u]]++;
            if(u!=s)u=pre[u];
        }
    }
    if(flow>=T)return true;
    return false;
}

inline void add(int u,int v,int w)
{
    e[ec].to=v;
    e[ec].w=w;
    e[ec].next=pp[u];
    pp[u]=ec++;
}
void make(int mid)
{
    int i,j,k;
    memset(c,0,sizeof(c));
    for(i=1;i<=n;i++)
    {
        for(j=pp[i];j!=-1;j=e[j].next)
        {
            k=e[j].to;
            if(e[j].w<=mid)
            {
                c[i][k]+=1;
                c[k][i]=c[i][k];
            }
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
        add(i,j,k);
        add(j,i,k);
    }
    //printf("%d %d\n",low,high);
    solve(1,n);
    //while(1);
    return 0;
}
