#include <stdio.h>
#include <stdlib.h>

#define MAXN 105

int edge[MAXN][MAXN],n,closedge[MAXN],visited[MAXN];

int res;

void prim()
{
    int i,j,k,beg;
    memset(visited,0,sizeof(visited));
    for(i=2;i<=n;i++)
    {
        closedge[i]=edge[1][i];
    }
    visited[1]=1;
    for(j=1;j<=n-1;j++)
    {
        k=1;
        while(visited[k])k++;
        beg=k;
        for(i=k+1;i<=n;i++)
        {
            if(closedge[i]<closedge[k])
            {
                k=i;
            }
        }
        visited[k]=1;
        res+=closedge[k];
        for(i=beg;i<=n;i++)
        {
            if(!visited[i]&&edge[k][i]<closedge[i])
            {
                closedge[i]=edge[k][i];
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int i,j;
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&edge[i][j]);
            }
        }
        res=0;
        prim();
        printf("%d\n",res);
    }
    return 0;
}
