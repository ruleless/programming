/*
prim求最小生成树，用priority_queue来优化算法 
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
#define N 1000
#define Inf 9999999
struct Edge
{
    int to,w,next;
}e[100000];
int ec,pp[N],closedge[N],n;
bool vis[N];
struct Node
{
    int u,d;
    bool operator<(const struct Node a)const
    {
        return d>a.d;
    }
}t1;

void prim(int s)
{
    int i,j,k;
    priority_queue<struct Node>que;
    for(i=1;i<=n;i++)
        closedge[i]=Inf;
    memset(vis,0,sizeof(vis));
    closedge[s]=0;
    t1.d=0;
    t1.u=s;
    que.push(t1);
    while(!que.empty())
    {
        t1=que.top();
        que.pop();
        k=t1.u;
        if(vis[k])continue;
        vis[k]=true;
        for(i=pp[k];i!=-1;i=e[i].next)
        {
            if(!vis[e[i].to]&&e[i].w<closedge[e[i].to])
            {
                closedge[e[i].to]=e[i].w;
                t1.d=e[i].w;
                t1.u=e[i].to;
                que.push(t1);
            }
        }
    }
}
int main()
{
}
