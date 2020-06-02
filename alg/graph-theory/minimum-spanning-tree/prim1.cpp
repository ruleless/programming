/*
prim求最小生成树，图用静态临界表表示 
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define N 1000
#define Inf 9999999
struct Edge
{
    int to,w,next;
}e[100000];
int pp[N],n,closedge[N];
bool vis[N];

void prim(int s)
{
    int i,j,k;
    for(i=1;i<=n;i++)
        closedge[i]=Inf;
    closedge[s]=0;
    memset(vis,0,sizeof(vis));
    for(j=1;j<=n;j++)
    {
        k=1;
        while(vis[k])k++;
        for(i=k+1;i<=n;i++)
            if(!vis[i]&&closedge[i]<closedge[k])
                k=i;
        vis[k]=true;
        for(i=pp[k];i!=-1;i=e[i].next)
            if(!vis[e[i].to]&&e[i].w<closedge[e[i].to])
                closedge[e[i].to]=e[i].w;
    }
}
int main()
{
}
