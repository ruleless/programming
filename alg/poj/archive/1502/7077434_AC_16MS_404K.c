#include <stdio.h>
#include <stdlib.h>

#define Max_N 105
#define Inf 1<<30

int edge[Max_N][Max_N],visited[Max_N],dist[Max_N],n;
int res;

void dijkstra(int s,int t)
{
    int i,j,k,beg;
    memset(visited,0,sizeof(visited));
    for(i=1;i<=n;i++)
    {
        dist[i]=edge[s][i];
    }
    visited[s]=1;
    for(i=1;i<=n-2;i++)
    {
        k=1;
        while(visited[k]==1)k++;
        beg=k;
        for(j=k;j<=n;j++)
        {
            if(!visited[j]&&dist[j]<dist[k])
            {
                k=j;
            }
        }
        visited[k]=1;
        for(j=beg;j<=n;j++)
        {
            if(!visited[j]&&dist[k]+edge[k][j]<dist[j])
            {
                dist[j]=dist[k]+edge[k][j];
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        if(dist[i]>res)
        {
            res=dist[i];
        }
    }
}

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    int i,j;
    char temp[Max_N];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        edge[i][i]=0;
        for(j=1;j<i;j++)
        {
            scanf("%s",temp);
            if(temp[0]=='x')
            {
                edge[i][j]=Inf;
                edge[j][i]=Inf;
            }
            else
            {
                int d;
                sscanf(temp,"%d",&d);
                edge[i][j]=d;
                edge[j][i]=d;
            }
        }
    }
    edge[n][n]=0;
    res=0;
    dijkstra(1,n);
    printf("%d\n",res);
    //while(1);
    //system("PAUSE");	
    return 0;
}
