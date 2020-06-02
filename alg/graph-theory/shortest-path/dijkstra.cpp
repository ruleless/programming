/*
dijkstraÇó×î¶ÌÂ· 
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define N 1000
#define Inf 9999999
int edge[N][N],dist[N],n,vis[N];

void dij(int s)
{
    int i,j,k;
    for(i=1;i<=n;i++)
        dist[i]=edge[s][i];
    memset(vis,0,sizeof(vis));
    vis[s]=true;
    for(j=1;j<=n-2;j++)
    {
        k=1;
        while(vis[k])k++;
        int beg=k;
        for(i=k+1;i<=n;i++)
            if(!vis[i]&&dist[i]<dist[k])
                k=i;
        vis[k]=true;
        for(i=1;i<=n;i++)
            if(!vis[i]&&dist[k]+edge[k][i]<dist[i])
                dist[i]=dist[k]+edge[k][i];
    }
}

int main()
{
}
