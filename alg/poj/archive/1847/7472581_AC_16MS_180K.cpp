#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define Inf 99999
#define N 106
int edge[N][N],n,dist[N];
bool vis[N];

int dij(int s,int t)
{
    int i,j,k;
    for(i=1;i<=n;i++)
        dist[i]=edge[s][i];
    memset(vis,0,sizeof(vis));
    vis[s]=true;
    for(j=1;j<=n-1;j++)
    {
        k=1;
        while(vis[k])k++;
        int beg=k;
        for(i=k+1;i<=n;i++)
            if(!vis[i]&&dist[i]<dist[k])
                k=i;
        vis[k]=true;
        if(k==t&&dist[k]!=Inf)
            return dist[k];
        for(i=beg;i<=n;i++)
        {
            if(!vis[i]&&dist[k]+edge[k][i]<dist[i])
                dist[i]=edge[k][i]+dist[k];
        }
    }
    return -1;
}

int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,k,s,t,l;
    scanf("%d%d%d",&n,&s,&t);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            edge[i][j]=Inf;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&k);
        for(j=1;j<=k;j++)
        {
            scanf("%d",&l);
            if(j==1)
                edge[i][l]=0;
            else
                edge[i][l]=1;
        }
    }
    printf("%d\n",dij(s,t));
    //while(1);
    return 0;
}
