#include <cstdlib>
#include <iostream>

using namespace std;

#define Inf 1<<20

struct Edge
{
    int u,v,w;
}edge[8000];
int n,cnt,dist[505];

void relax(struct Edge a)
{
    if(dist[a.u]+a.w<dist[a.v])
    {
        dist[a.v]=dist[a.u]+a.w;
    }
}

int bellman_ford()
{
    int i,j,k;
    dist[1]=0;
    for(i=2;i<=n;i++)
    {
        dist[i]=Inf;
    }
    for(i=1;i<=n-1;i++)
    {
        for(j=0;j<cnt;j++)
        {
            relax(edge[j]);
        }
    }
    for(i=0;i<cnt;i++)
    {
        if(dist[edge[i].u]+edge[i].w<dist[edge[i].v])
        {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    int i,j,k,m,w,t;
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;
        scanf("%d%d%d",&n,&m,&w);
        while(m--)
        {
            scanf("%d%d%d",&i,&j,&k);
            edge[cnt].u=i;
            edge[cnt].v=j;
            edge[cnt].w=k;
            cnt++;
            edge[cnt].u=j;
            edge[cnt].v=i;
            edge[cnt].w=k;
            cnt++;
        }
        while(w--)
        {
            scanf("%d%d%d",&i,&j,&k);
            edge[cnt].u=i;
            edge[cnt].w=j;
            edge[cnt].w=-k;
            cnt++;
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
