/*
dijkstra求最短路,图用静态邻接表表示 
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define N 10000
#define Inf 9999999
struct Edge
{
    int to,w,next;
}e[100000];
int ec,pp[N],n,dist[N];
bool vis[N];

void dij(int s)
{
    int i,j,k;
    memset(vis,0,sizeof(vis));
    for(i=1;i<=n;i++)
        dist[i]=Inf;
    dist[s]=0;
    for(j=1;j<=n-1;j++)
    {
        k=1;
        while(vis[k])k++;
        for(i=k+1;i<=n;i++)
            if(!vis[i]&&dist[i]<dist[k])
                k=i;
        vis[k]=true;
        for(i=pp[k];i!=-1;i=e[i].next)
            if(!vis[e[i].to]&&dist[k]+e[i].w<dist[e[i].to])
                dist[e[i].to]=dist[k]+e[i].w;
    }
}
int main()
{}
