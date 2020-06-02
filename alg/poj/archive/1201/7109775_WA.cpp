#include <cstdlib>
#include <iostream>

using namespace std;

#define MAXINT 100000

struct Edge
{
    int u,v,w;
}edge[50006];

int cnt,Min,Max,dist[50005];

int bellman()
{
    int i,j,k;
    for(i=Min;i<=Max;i++)
    {
        dist[i]=-MAXINT;
    }
    dist[Min]=0;
    k=Max-Min+1;
    while(k--)
    {
        for(i=0;i<cnt;i++)
        {
            if(dist[edge[i].v]!=-MAXINT&&dist[edge[i].u]+edge[i].w>dist[edge[i].v])
            {
                dist[edge[i].v]=dist[edge[i].u]+edge[i].w;
            }
        }
        for(i=Min;i<Max;i++)
        {
            if(dist[i+1]!=-MAXINT&&dist[i+1]<dist[i])
            {
                dist[i+1]=dist[i];
            }
        }
        for(i=Max;i>Min;i--)
        {
            if(dist[i]!=-MAXINT&&dist[i]<dist[i-1]+1)
            {
                dist[i]=dist[i-1]+1;
            }
        }
    }
    return dist[Max];
}

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    int i,j,k,n,t;
    scanf("%d",&t);
    cnt=0;
    Min=MAXINT;
    Max=0;
    while(t--)
    {
        scanf("%d%d%d",&i,&j,&k);
        i--;
        if(i<Min)
        {
            Min=i;
        }
        if(j>Max)
        {
            Max=j;
        }
        edge[cnt].u=i;
        edge[cnt].v=j;
        edge[cnt++].w=k;
    }
    printf("%d\n",bellman());
    //while(1);
    //system("PAUSE");
    return EXIT_SUCCESS;
}
