/*
dijkstra求最小生成树,用priority_queue优化 
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
#define Inf 9999999
#define N 1000
struct Edge
{
    int to,w,next;
}e[100000];
int ec,pp[N],n,dist[N];
bool vis[N];
struct Node
{
    int u,d;
    bool operator<(const struct Node a)const
    {
        return d>a.d;
    }
}t1;
void dijkstra(int s)
{
    int i,j,k;
    priority_queue<struct Node>que;
    memset(vis,0,sizeof(vis));
    for(i=1;i<=n;i++)
        dist[i]=Inf;
    dist[s]=0;
    t1.u=s;t1.d=0;
    que.push(t1);
    while(!que.empty())
    {
        t1=que.top();
        que.pop();
        k=t1.u;
        if(vis[k])continue;
        vis[k]=true;
        for(i=pp[k];i!=-1;i=e[i].next)
            if(!vis[e[i].to]&&dist[k]+e[i].w<dist[e[i].to])
            {
                dist[e[i].to]=dist[k]+e[i].w;
                t1.u=e[i].to;
                t1.d=dist[e[i].to];
                que.push(t1);
            }
    }
}
int main()
{
}
