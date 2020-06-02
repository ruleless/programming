#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define Inf 99999999
#define N 1520
int dist[N],n,cnt;
struct Edge
{
    int u,v,w;
}e[10000];
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
    //freopen("in.txt","r",stdin);
    int i,j,k,t,m,w;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&w);
        cnt=0;
        while(m--)
        {
            scanf("%d%d%d",&i,&j,&k);
            e[cnt].u=i;
            e[cnt].v=j;
            e[cnt++].w=k;
            e[cnt].u=j;
            e[cnt].v=i;
            e[cnt++].w=k;
        }
        while(w--)
        {
            scanf("%d%d%d",&i,&j,&k);
            e[cnt].u=i;
            e[cnt].v=j;
            e[cnt++].w=-k;
        }
        if(bellman(1))
            printf("YES\n");
        else
            printf("NO\n");
    }
    //while(1);
    return 0;
}
