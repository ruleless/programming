/*
bellman_ford求最短路,用结构体存储边 
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define N 1000
#define Inf 9999999
struct Edge
{
    int u,v,w;
}e[10000];
int n,dist[N],cnt;

bool bellman(int s)//存在负权回路返回true，否则返回false 
{
    int i,j,k;
    for(i=1;i<=n;i++)
        dist[i]=Inf;
    dist[s]=0;
    for(j=1;j<=n-1;j++)
    {
        bool flag=true;
        for(i=0;i<cnt;i++)
        {
            if(dist[e[i].u]+e[i].w<dist[e[i].v])
            {
                flag=false;
                dist[e[i].v]=dist[e[i].u]+e[i].w;
            }
        }
        if(flag)
            return false;
    }
    for(i=0;i<cnt;i++)
        if(dist[e[i].u]+e[i].w<dist[e[i].v])
            return true;
    return false;
}

int main()
{
}
