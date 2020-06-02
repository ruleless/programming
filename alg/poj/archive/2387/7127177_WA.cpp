#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;

#define MAX 1000000

int n,edge[1005][1005],dist[1005],visited[1005];

void spfa(int s)
{
    int i,j,k;
    queue<int>que;
    for(i=1;i<=n;i++)
    {
        dist[i]=MAX;
    }
    dist[s]=0;
    memset(visited,0,sizeof(visited));
    que.push(s);
    visited[s]=1;
    while(!que.empty())
    {
        k=que.front();
        que.pop();
        visited[k]=0;
        for(i=1;i<=n;i++)
        {
            if(dist[k]+edge[k][i]<dist[i])
            {
                dist[i]=dist[k]+edge[k][i];
                if(!visited[i])
                {
                    que.push(i);
                    visited[i]=1;
                }
            }
        }
    }
}
struct Node
{
    int u,d;
    bool operator<(const struct Node& a)const
    {
        return d>a.d;
    }
}t1,t2;

priority_queue<struct Node>que;

int dij(int s,int t)
{
    int i,j,k=0;
    dist[0]=1<<30;
    for(i=1;i<=n;i++)
    {
        dist[i]=edge[s][i];
        if(dist[i]<dist[k])
        {
            k=i;
        }
    }
    t1.u=k;
    t1.d=dist[k];
    que.push(t1);
    memset(visited,0,sizeof(visited));
    visited[s]=1;
    while(!que.empty())
    {
        t1=que.top();
        que.pop();
        if(t1.u==t)
        {
            return t1.d;
        }
        for(i=1;i<=n;i++)
        {
            if(!visited[i])
            {
                if(t1.d+edge[t1.u][i]<dist[i])
                {
                    dist[i]=t1.d+edge[t1.u][i];
                    t2.u=i;
                    t2.d=dist[i];
                    que.push(t2);
                }
            }
        }
    }
}

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    int i,j,k,t;
    scanf("%d%d",&t,&n);
    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;j++)
        {
            edge[i][j]=MAX;
            edge[j][i]=MAX;
        }
    }
    while(t--)
    {
        scanf("%d%d%d",&i,&j,&k);
        if(k<edge[i][j])
        {
            edge[i][j]=k;
            edge[j][i]=k;
        }
    }
    printf("%d\n",dij(n,1));
    //while(1);
    //system("PAUSE");
    return EXIT_SUCCESS;
}
