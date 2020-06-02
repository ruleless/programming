#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

#define Max_N 205

int n,visited[Max_N];
double closedge[Max_N],edge[Max_N][Max_N];
struct Point 
{
    int x,y;
}point[Max_N];

double res;

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
        k=2;
        while(visited[k])k++;
        beg=k;
        for(i=k+1;i<=n;i++)
        {
            if(!visited[i]&&closedge[i]<closedge[k])
            {
                k=i;
            }
        }
        
        visited[k]=1;
        if(closedge[k]>res)
        {
            res=closedge[k];
        }
        if(k==2)
        {
            break;
        }
        for(i=beg;i<=n;i++)
        {
            if(!visited[i]&&edge[k][i]<closedge[i])
            {
                closedge[i]=edge[k][i];
            }
        }
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,k,cse=0;
    while(scanf("%d",&n)!=EOF&&n)
    {
        
        cse++;
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&point[i].x,&point[i].y);
        }
        for(i=1;i<=n;i++)
        {
            for(j=i;j<=n;j++)
            {
                edge[i][j]=sqrt( 1.0*(point[i].x-point[j].x)*(point[i].x-point[j].x)
                +1.0*(point[i].y-point[j].y)*(point[i].y-point[j].y) );
                edge[j][i]=edge[i][j];
            }
        }
        /*for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                printf("%.3lf ",edge[i][j]);
            }
            printf("\n");
        }*/
        res=0;
        prim();
        printf("Scenario #%d\nFrog Distance = %.3lf\n\n",cse,res);
    }
    //while(1);
    //system("PAUSE");
    return 0;
}
