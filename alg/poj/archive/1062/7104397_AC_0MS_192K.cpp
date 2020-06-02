#include <cstdlib>
#include <iostream>

using namespace std;

#define MAXN 106
#define Inf 1<<29

int n,visited[MAXN],edge[MAXN][MAXN],dist[MAXN],rank[MAXN];

int dij(int s,int t,int _min,int _max)
{
    int i,j,k,beg;
    memset(visited,0,sizeof(visited));
    for(i=1;i<=n+1;i++)
    {
        dist[i]=edge[s][i];
    }
    visited[s]=1;
    for(j=1;j<=n;j++)
    {
        k=1;
        while(visited[k]|| !(rank[k]>=_min&&rank[k]<=_max) )k++;
        beg=k;
        for(i=k+1;i<=n+1;i++)
        {
            if(!visited[i]&&rank[i]>=_min&&rank[i]<=_max
            &&dist[i]<dist[k])
            {
                k=i;
            }
        }
        visited[k]=1;
        if(k==t)
        {
            return dist[k];
        }
        for(i=beg;i<=n+1;i++)
        {
            if(!visited[i]&&rank[i]>=_min&&rank[i]<=_max
            &&(dist[k]+edge[k][i]<dist[i]))
            {
                dist[i]=dist[k]+edge[k][i];
            }
        }
    }
}

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    int i,j,k,p,l,x,m;
    scanf("%d%d",&m,&n);
    for(i=1;i<=n+1;i++)
    {
        for(j=1;j<=n+1;j++)
        {
            edge[i][j]=Inf;
        }
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d",&p,&rank[i],&x);
        edge[i][n+1]=p;
        while(x--)
        {
            scanf("%d%d",&j,&p);
            edge[i][j]=p;
        }
    }
    rank[n+1]=rank[1];
    int res=1<<30;
 /*   for(i=1;i<=n+1;i++)
    {
        for(j=1;j<=n+1;j++)
        {
            printf("%d ",edge[i][j]);
        }
        printf("\n");
    }*/
    for(i=rank[1];i<=rank[1]+m;i++)
    {
        int temp=dij(1,n+1,i-m,i);
        if(temp<res)
        {
            res=temp;
        }
    }
    printf("%d\n",res);
    //while(1);
    //system("PAUSE");
    return EXIT_SUCCESS;
}
