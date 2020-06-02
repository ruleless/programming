#include<iostream>
using namespace std;

int edge[501][501];
bool flag[501];
int closedge[501];

int main()
{
//	freopen("in.txt","r",stdin);
	int t,n,i,j,sum,Min;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&edge[i][j]);
		sum=0;
		memset(flag,0,sizeof(flag));
		for(i=0;i<n;i++)
			closedge[i]=edge[0][i];
		flag[0]=true;
		for(i=1;i<n;i++)
		{
			for(Min=1;flag[Min]==true;Min++);
			for(j=Min+1;j<n;j++)
			{
				if(!flag[j])
				{
					if(closedge[j]<closedge[Min])
						Min=j;
				}
			}
			flag[Min]=true;
			if(closedge[Min]>sum)
				sum=closedge[Min];
			for(j=1;j<n;j++)
			{
				if(!flag[j])
				{
					if(edge[Min][j]<closedge[j])
						closedge[j]=edge[Min][j];
				}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}