#include<iostream>
#include<cmath>
using namespace std;

struct Node
{
	double x,y;
}node[102];
bool flag[102];

int n;

double edge[102][102],closedge[102];

double prim()
{
	int i,j,Min;
	double sum=0;
	flag[1]=true;
	for(i=2;i<=n;i++)
	{
		closedge[i]=edge[1][i];
		flag[i]=false;
	}
	for(i=1;i<n;i++)
	{
		for(Min=2;flag[Min]==true;Min++);
		for(j=Min+1;j<=n;j++)
			if(!flag[j])
				if(closedge[j]<closedge[Min])
					Min=j;
		flag[Min]=true;
		sum+=closedge[Min];
		for(j=2;j<=n;j++)
		{
			if(!flag[j])
			{
				if(edge[Min][j]<closedge[j])
					closedge[j]=edge[Min][j];
			}
		}
	}
	return sum;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%lf%lf",&node[i].x,&node[i].y);
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
		{
			if(i==j)
				edge[i][j]=0;
			else
			{
				edge[i][j]=sqrt( (node[i].x-node[j].x)*(node[i].x-node[j].x)+(node[i].y-node[j].y)*(node[i].y-node[j].y) );
				edge[j][i]=edge[i][j];
			}
		}
	printf("%.2lf\n",prim());
	return 0;
}