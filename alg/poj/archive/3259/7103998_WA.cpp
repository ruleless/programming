#include <cstdlib>
#include <iostream>

using namespace std;
#define MAXN 505
#define Inf 1000000


int n,edge[MAXN][MAXN],dist[MAXN];

int bellman_ford()
{
    int i,j,k;
    dist[1]=0;
    for(i=2;i<=n;i++)
    {
        dist[i]=Inf;
    }
    for(k=1;k<=n-1;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(!edge[i][j]&&(dist[i]+edge[i][j]<dist[j]))
                {
                    dist[j]=dist[i]+edge[i][j];
                }
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(!edge[i][j]&&(dist[i]+edge[i][j]<dist[j]))
            {
                return 0;
            }
        }
    }
    return 1;
}

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    int m,w,i,j,k,t;
    scanf("%d",&t);
    while(t--)
    {
        memset(edge,0,sizeof(edge));
        scanf("%d%d%d",&n,&m,&w);
        while(m--)
        {
            scanf("%d%d%d",&i,&j,&k);
            edge[i][j]=k;
        }
        while(w--)
        {
            scanf("%d%d%d",&i,&j,&k);
            edge[i][j]=-k;
        }
        if(bellman_ford())
        {
            printf("NO\n");  
        }
        else
        {
            printf("YES\n");
        }
    }
    //while(1);
    //system("PAUSE");
    return EXIT_SUCCESS;
}
