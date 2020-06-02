#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct Point
{
    int node;
    double x,y;
}temp[300][300],beg,end,tt;
int row[300];
double edge[300][300],dist[300];
int visited[300],n;

double dijkstra(int s,int t)
{
    int i,j,k,beg;
    memset(visited,0,sizeof(visited));
    for(i=1;i<=n;i++)
    {
        dist[i]=edge[s][i];
    }
    visited[s]=1;
    for(j=1;j<=n-2;j++)
    {
        k=1;
        while(visited[k]==1)k++;
        beg=k;
        for(i=k;i<=n;i++)
        {
            if(!visited[i]&&dist[i]<dist[k])
            {
                k=i;
            }
        }
        visited[k]=1;
        if(k==t)
        {
            return dist[t];
        }
        for(i=beg;i<=n;i++)
        {
            if(!visited[i]&&dist[k]+edge[k][i]<dist[i])
            {
                dist[i]=dist[k]+edge[k][i];
            }
        }
    }
    return dist[t];
}

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    int i,j,k,m=0,l;
    n=2;
    scanf("%lf%lf%lf%lf",&beg.x,&beg.y,&end.x,&end.y);
    memset(row,0,sizeof(row));
    while(scanf("%lf%lf",&tt.x,&tt.y)!=EOF)
    {
        temp[m][row[m]].node=++n;
        temp[m][row[m]].x=tt.x;
        temp[m][row[m]++].y=tt.y;
        while(scanf("%lf%lf",&tt.x,&tt.y)&&!(tt.x==-1&&tt.y==-1))
        {
            temp[m][row[m]].node=++n;
            temp[m][row[m]].x=tt.x;
            temp[m][row[m]++].y=tt.y;
        }
        m++;
    }
    memset(edge,0,sizeof(edge));
    double sum;
    sum=sqrt( (end.x-beg.x)*(end.x-beg.x)+(end.y-beg.y)*(end.y-beg.y) )*3.6/600;
    edge[1][2]=sum;
    edge[2][1]=sum;
    for(i=0;i<m;i++)
    {
        for(j=0;j<row[i];j++)
        {
            sum=sqrt( (temp[i][j].x-beg.x)*(temp[i][j].x-beg.x)+(temp[i][j].y-beg.y)*(temp[i][j].y-beg.y) )*3.6/600;
            edge[1][temp[i][j].node]=sum;
            edge[temp[i][j].node][1]=sum;
            sum=sqrt( (temp[i][j].x-end.x)*(temp[i][j].x-end.x)+(temp[i][j].y-end.y)*(temp[i][j].y-end.y) )*3.6/600;
            edge[2][temp[i][j].node]=sum;
            edge[temp[i][j].node][2]=sum;
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<row[i];j++)
        {
            if(j+1<row[i])
            {
                sum=sqrt( (temp[i][j].x-temp[i][j+1].x)*(temp[i][j].x-temp[i][j+1].x)+(temp[i][j].y-temp[i][j+1].y)*(temp[i][j].y-temp[i][j+1].y) )*3.6/2400;
                edge[temp[i][j].node][temp[i][j+1].node]=sum;
                edge[temp[i][j+1].node][temp[i][j].node]=sum;
            }
            for(k=j+2;k<row[i];k++)
            {
                sum=sqrt( (temp[i][j].x-temp[i][k].x)*(temp[i][j].x-temp[i][k].x)+(temp[i][j].y-temp[i][k].y)*(temp[i][j].y-temp[i][k].y) )*3.6/600;
                edge[temp[i][j].node][temp[i][k].node]=sum;
                edge[temp[i][k].node][temp[i][j].node]=sum;
            }
            for(k=i+1;k<m;k++)
            {
                for(l=0;l<row[k];l++)
                {
                    sum=sqrt( (temp[i][j].x-temp[k][l].x)*(temp[i][j].x-temp[k][l].x)+(temp[i][j].y-temp[k][l].y)*(temp[i][j].y-temp[k][l].y) )*3.6/600;
                    edge[temp[i][j].node][temp[k][l].node]=sum;
                    edge[temp[k][l].node][temp[i][j].node]=sum;
                }
            }
        }
    }
    /*for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%.0lf ",edge[i][j]);
        }
        printf("\n");
    }*/
    printf("%.0lf\n",dijkstra(1,2));
    //while(1);
    //system("PAUSE");	
    return 0;
}
