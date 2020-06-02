/*
prim求最小生成树,图用邻接矩阵表示 
*/
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
#define N 1000

int edge[N][N],closedge[N],n;
bool vis[N];
void prim(int s)
{
    int i,j,k;
    for(i=1;i<=n;i++)
        closedge[i]=edge[s][i];
    memset(vis,0,sizeof(vis));
    vis[s]=true;
    for(j=1;j<=n-1;j++)
    {
        k=1;
        while(vis[k])k++;
        int beg=k;
        for(i=k+1;i<=n;i++)
            if(!vis[i]&&closedge[i]<closedge[k])
                k=i;
        vis[k]=true;
        for(i=beg;i<=n;i++)
            if(!vis[i]&&edge[k][i]<closedge[i])
                closedge[i]=edge[k][i];
    }
}

int main()
{
}
