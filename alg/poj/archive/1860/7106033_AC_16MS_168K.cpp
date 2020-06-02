#include <cstdlib>
#include <iostream>

using namespace std;

#define eps 10e-8

struct Edge
{
    int beg,end;
    double c,r;
}edge[250];
double dist[120];
int n,cnt,s;
double money;

void relax(struct Edge &a)
{
    if(( (dist[a.beg]-a.c)*a.r )-dist[a.end]>eps)
    {
        dist[a.end]=(dist[a.beg]-a.c)*a.r;
    }
}

int bellman()
{
    memset(dist,0,sizeof(dist));
    int i,j;
    dist[s]=money;
    for(i=1;i<=n-1;i++)
    {
        for(j=0;j<cnt;j++)
        {
            relax(edge[j]);
        }
    }
    for(j=0;j<cnt;j++)
    {
        if(( (dist[edge[j].beg]-edge[j].c)*edge[j].r )-dist[edge[j].end]>eps)
        {
            return 1;
        }
    }
    if(dist[s]>money)
    {
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[])
{
//    freopen("in.txt","r",stdin);
    int i,j,k,m;
    double r1,c1,r2,c2;
    scanf("%d%d%d%lf",&n,&m,&s,&money);
    cnt=0;
    while(m--)
    {
        scanf("%d%d%lf%lf%lf%lf",&i,&j,&r1,&c1,&r2,&c2);
        edge[cnt].beg=i;
        edge[cnt].end=j;
        edge[cnt].r=r1;
        edge[cnt].c=c1;
        cnt++;
        edge[cnt].beg=j;
        edge[cnt].end=i;
        edge[cnt].r=r2;
        edge[cnt].c=c2;
        cnt++;
    }
    if(bellman())
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
 //   while(1);
  //  system("PAUSE");
    return EXIT_SUCCESS;
}
