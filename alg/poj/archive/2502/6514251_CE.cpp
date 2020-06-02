#include <stdio.h>
#include <stdlib.h>
#define inf 10000000.

int count[300];
int visit[300];
double dist[300];
double edge[300][300];
int cnt;
int cnt_p;
int t;

struct Node
{
    int x,y,z;
}beg,end,point[300][300],temp;

void floyd()
{
    int i,j,k;
    for(k=0;k<=t;k++)
    {
        for(i=0;i<=t;i++)
        {
            for(j=0;j<=t;j++)
            {
                if(edge[i][k]+edge[k][j]<edge[i][j])
                {
                    edge[i][j]=edge[i][k]+edge[k][j];
                }
            }
        }
    }
}

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    int i,j,k,l;
    cnt=0;
    cnt_p=1;
    memset(count,0,sizeof(count));
    for(i=0;i<300;i++)
    {
        for(j=0;j<300;j++)
        {
            if(i==j)
            {
                edge[i][j]=0;
            }
            else
                edge[i][j]=inf;
        }
    }
    scanf("%d%d%d%d",&beg.x,&beg.y,&end.x,&end.y);
    while(scanf("%d%d",&temp.x,&temp.y)!=EOF)
    {
        point[cnt][count[cnt]].x=temp.x;
        point[cnt][count[cnt]].y=temp.y;
        point[cnt][count[cnt]].z=cnt_p++;
        //printf("%d\n",cnt_p);
        count[cnt]++;
        while(scanf("%d%d",&temp.x,&temp.y)&&!(temp.x==-1&&temp.y==-1))
        {
            point[cnt][count[cnt]].x=temp.x;
            point[cnt][count[cnt]].y=temp.y;
            point[cnt][count[cnt]].z=cnt_p++;
            //printf("%d\n",point[cnt][count[cnt]].z);
            count[cnt]++; 
            //printf("%d\n",cnt_p);     
        }
        cnt++;
    }
    t=point[cnt-1][count[cnt-1]-1].z+1;
    edge[0][t]=sqrt( ((beg.x-end.x)*(beg.x-end.x)+(beg.y-end.y)*(beg.y-end.y))*1.0 )*.36/60;
    for(i=0;i<cnt;i++)
    {
        for(j=0;j<count[i];j++)
        {
            edge[0][point[i][j].z]=sqrt( ((point[i][j].x-beg.x)*(point[i][j].x-beg.x)+(point[i][j].y-beg.y)*(point[i][j].y-beg.y))*1.0 )*.36/60;
            edge[point[i][j].z][t]=sqrt( ((point[i][j].x-end.x)*(point[i][j].x-end.x)+(point[i][j].y-end.y)*(point[i][j].y-end.y))*1.0 )*.36/60;
        }
    }
    for(i=0;i<cnt;i++)
    {
        for(j=0;j<count[i]-1;j++)
        {
            edge[point[i][j].z][point[i][j+1].z]=sqrt( ((point[i][j].x-point[i][j+1].x)*(point[i][j].x-point[i][j+1].x)+(point[i][j].y-point[i][j+1].y)*(point[i][j].y+point[i][j+1].y))*1.0 )*3.6/2400;
            edge[point[i][j+1].z][point[i][j].z]=sqrt( ((point[i][j].x-point[i][j+1].x)*(point[i][j].x-point[i][j+1].x)+(point[i][j].y-point[i][j+1].y)*(point[i][j].y+point[i][j+1].y))*1.0 )*3.6/2400;
        }
    }
    for(i=0;i<cnt;i++)
    {
        for(j=0;j<count[i];j++)
        {
            for(k=0;k<cnt;k++)
            {
                if(k!=i)
                {
                    for(l=0;l<count[k];l++)
                    {
                        edge[point[i][j].z][point[k][l].z]=sqrt( ((point[i][j].x-point[k][l].x)*(point[i][j].x-point[k][l].x)+(point[i][j].y-point[k][l].y)*(point[i][j].y-point[k][l].y))*1.0 )*.36/60;
                    }
                }
            }
        }
    }
    floyd();
    double res=edge[0][t];
    int d=floor(res);
    if( (res-d)<.5 );
    else
    {
        d+=1;
    }
    printf("%d\n",d);
    /*for(i=0;i<=t;i++)
    {
        for(j=0;j<=t;j++)
        {
            printf("%.0lf ",edge[i][j]);
        }
        printf("\n");
    }*/
    /*for(i=0;i<cnt;i++)
    {
        for(j=0;j<count[i];j++)
        {
            printf("%d %d ",point[i][j].x,point[i][j].y);
        }
        printf("\n");
    }*/
    //while(1);
  //system("PAUSE");	
  return 0;
}
