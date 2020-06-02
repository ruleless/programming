#include<iostream>
#include<cmath>
using namespace std;

struct Node
{
	double x,y;
}node[1002];

double closedge[1002],edge[1002][1002];

bool flag[1002];

int main()
{
//	freopen("in.txt","r",stdin);
	int N,M,i,j,Min;
	double temp,sum=0;
	scanf("%d%d",&N,&M);
	for(i=1;i<=N;i++)
		scanf("%lf%lf",&node[i].x,&node[i].y);
	for(i=1;i<=N;i++)
		for(j=i;j<=N;j++)
		{
			if(i==j)
				edge[i][j]=0;
			else
			{
				edge[i][j]=sqrt( (node[i].x-node[j].x)*(node[i].x-node[j].x)+(node[i].y-node[j].y)*(node[i].y-node[j].y) );
				edge[j][i]=edge[i][j];
			}
		}
	memset(flag,0,sizeof(flag));
	while(M--)
	{
		scanf("%d%d",&i,&j);
		edge[i][j]=0;
		edge[j][i]=0;
	}
	flag[1]=true;
	for(i=2;i<=N;i++)
		closedge[i]=edge[1][i];
	for(i=1;i<N;i++)
	{
		for(Min=2;flag[Min]==true;Min++);
		for(j=Min+1;j<=N;j++)
		{
			if(!flag[j])
				if(closedge[j]<closedge[Min])
					Min=j;
		}
		flag[Min]=true;
		sum+=closedge[Min];
		for(j=2;j<=N;j++)
		{
			if(!flag[j])
			{
				if(edge[Min][j]<closedge[j])
					closedge[j]=edge[Min][j];
			}
		}
	}
	printf("%.2lf\n",sum);
	return 0;
}