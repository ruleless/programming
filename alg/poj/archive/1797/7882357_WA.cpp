#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define N 1010
bool vis[N];
int dist[N],edge[N][N],n;

int dij(int s)
{
    int i,j,k,res=9999999;
    memset(vis,0,sizeof(vis));
    for(i=1;i<=n;i++)
        dist[i]=edge[s][i];
    dist[s]=0;
    vis[s]=true;
    for(j=1;j<=n-2;j++)
    {
        k=1;
        while(vis[k])k++;
        int beg=k;
        for(i=k+1;i<=n;i++)
            if(!vis[i]&&dist[i]>dist[k])
                k=i;
        vis[k]=true;
        for(i=beg;i<=n;i++)
            if(!vis[i]&&edge[k][i]<dist[i])
                dist[i]=edge[k][i];
    }
    return dist[n];
}

int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,k,cse=0,t,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(edge,0,sizeof(edge));
        while(m--)
        {
            scanf("%d%d%d",&i,&j,&k);
            edge[i][j]=edge[j][i]=k;
        }
        printf("Scenario #%d:\n%d\n\n",++cse,dij(1));
    }
    //while(1);
    return 0;
}
