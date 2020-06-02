#include<iostream>
#include<cmath>
using namespace std;

struct Node
{
	double x,y;
}node[1002];

double closedge[1002];

bool flag[1002];

int main()
{
//	freopen("in.txt","r",stdin);
	int N,M,i,j,k,Min;
	double temp,sum=0;
	scanf("%d%d",&N,&M);
	for(i=1;i<=N;i++)
		scanf("%lf%lf",&node[i].x,&node[i].y);
	memset(flag,0,sizeof(flag));
	k=0;
	while(M--)
	{
		scanf("%d%d",&i,&j);
		flag[i]=true;
		k++;
		flag[j]=true;
		k++;
	}
	for(i=1;i<=N;i++)
	{
		if(!flag[i])
		{
			closedge[i]=1e20;
			for(j=1;j<=N;j++)
			{
				if(flag[j])
				{
					temp=sqrt( (node[j].x-node[i].x)*(node[j].x-node[i].x)+(node[j].y-node[i].y)*(node[j].y-node[i].y) );
					if(temp<closedge[i])
						closedge[i]=temp;
				//	printf("%lf\n",closedge[i]);
				}
			}
		}
	}
	
	while(k!=N)
	{
	//	printf("%d\n",k);
		for(Min=1;flag[Min]==true;Min++);
		for(i=Min+1;i<=N;i++)
			if(!flag[i])
				if(closedge[i]<closedge[Min])
					Min=i;
		flag[Min]=true;
	//	printf("%d\n",Min);
		sum+=closedge[Min];
		k++;
		for(i=1;i<=N;i++)
		{
			if(!flag[i])
			{
				temp=sqrt( (node[Min].x-node[i].x)*(node[Min].x-node[i].x)+(node[Min].y-node[i].y)*(node[Min].y-node[i].y) );
				if(temp<closedge[i])
					closedge[i]=temp;
			}
		}
	}
	printf("%.2lf\n",sum);
	return 0;
}