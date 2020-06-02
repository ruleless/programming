#include <cstdlib>
#include <iostream>

using namespace std;

struct Edge
{
    int u,v,w;
}edge[10005];
#define MAX 10000000
int Min,Max,n;
int dist[10005];

int bellman()
{
    int i,j,k;
    k=Max-Min;
    for(i=Min;i<=Max;i++)
    {
        dist[i]=-MAX;
    }
    dist[Min]=0;
    int flag;
    while(k--)
    {
        flag=1;
        for(i=0;i<n;i++)
        {
            if(dist[edge[i].u]+2>dist[edge[i].v])
            {
                flag=0;
                dist[edge[i].v]=dist[edge[i].u]+2;
            }
        }
        for(i=Min;i<Max;i++)
        {
            if(dist[i+1]<dist[i])
            {
                flag=0;
                dist[i+1]=dist[i];   
            }
        }
        for(i=Max;i>Min;i--)
        {
            if(dist[i]>dist[i-1]+1)
            {
                flag=0;
                dist[i-1]=dist[i]-1;
            }
        }
        if(flag)
        {
          //  break;
        }
    }
    return dist[Max];
}

int main(int argc, char *argv[])
{
 //   freopen("in.txt","r",stdin);
    int i,j,k;
    scanf("%d",&n);
    Min=1<<30;
    Max=0;
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&edge[i].u,&edge[i].v);
        edge[i].v++;
        edge[i].w=2;
        if(edge[i].u<Min)
        {
            Min=edge[i].u;
        }
        if(edge[i].v>Max)
        {
            Max=edge[i].v;
        }
    }
    printf("%d\n",bellman());
  //  while(1);
  //  system("PAUSE");
    return EXIT_SUCCESS;
}
