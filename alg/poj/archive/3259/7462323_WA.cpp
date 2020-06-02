#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define Inf 9999999
#define N 520
int dist[N],n,edge[N][N];

bool bellman(int s)//存在负权回路返回ture，不存在则返回false 
{
    int i,j,k;
    for(i=1;i<=n;i++)
        dist[i]=Inf;
    dist[s]=0;
    for(k=1;k<=n-1;k++)
    {
        bool flag=true;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(dist[i]+edge[i][j]<dist[j])
                {
                    flag=false;
                    dist[j]=dist[i]+edge[i][j];
                }
            }
        }
        if(flag)
            return false;
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(dist[i]+edge[i][j]<dist[j])
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
        for(i=1;i<=n;i++)
            for(j=i;j<=n;j++)
                edge[i][j]=edge[j][i]=Inf;
        while(m--)
        {
            scanf("%d%d%d",&i,&j,&k);
            edge[i][j]=edge[j][i]=k;
        }
        while(w--)
        {
            scanf("%d%d%d",&i,&j,&k);
            edge[i][j]=-k;
        }
        if(bellman(1))
            printf("YES\n");
        else
            printf("NO\n");
    }
    //while(1);
    return 0;
}
