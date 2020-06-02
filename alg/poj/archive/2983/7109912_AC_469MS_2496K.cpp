#include <cstdlib>
#include <iostream>

using namespace std;
#define MAX 10000000

int n,cnt,dist[1005];

struct Edge
{
    int u,v,w;
}edge[200006];

int bellman()
{
    int i,j,k,flag;
    for(i=1;i<=n;i++)
    {
        dist[i]=-MAX;
    }
    dist[i]=0;
    for(k=1;k<=n-1;k++)
    {
        flag=1;
        for(i=0;i<cnt;i++)
        {
            if(dist[edge[i].v]-dist[edge[i].u]<edge[i].w)
            {
                flag=0;
                dist[edge[i].v]=dist[edge[i].u]+edge[i].w;
            }
        }
        if(flag)
        {
            return 1;
        }
    }
    for(i=0;i<cnt;i++)
    {
        if(dist[edge[i].v]-dist[edge[i].u]<edge[i].w)
        {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    int i,j,k,m;
    char temp[5];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        cnt=0;
        while(m--)
        {
            scanf("%s",temp);
            if(temp[0]=='V')
            {
                scanf("%d%d",&i,&j);
                edge[cnt].u=j;
                edge[cnt].v=i;
                edge[cnt++].w=1;
            }
            else
            {
                scanf("%d%d%d",&i,&j,&k);
                edge[cnt].u=j;
                edge[cnt].v=i;
                edge[cnt++].w=k;
                edge[cnt].u=i;
                edge[cnt].v=j;
                edge[cnt++].w=-k;
            }
        }
        if(bellman())
        {
            printf("Reliable\n");
        }
        else
        {
            printf("Unreliable\n");
        }
    }
   // while(1);
    //system("PAUSE");
    return EXIT_SUCCESS;
}
