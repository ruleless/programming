#include<iostream>
#define Max 2000000
using namespace std;


int edge[2000][2000];
int dist[2000];
bool flag[2000];

int main()
{
//	freopen("in.txt","r",stdin);
	int t,n,m,i,j,k,l,r,d;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		memset(flag,0,sizeof(flag));
		scanf("%d%d",&n,&m);
		if(n==1)
		{
			printf("Scenario #%d:\n",i);
	    	printf("0\n\n");
			continue;
		}

		for(l=1;l<=n;l++)
			for(r=1;r<=n;r++)
				edge[l][r]=0;
		for(j=1;j<=m;j++)
		{
			scanf("%d%d%d",&l,&r,&d);
			edge[l][r]=d;
			edge[r][l]=d;
		}
		for(j=2;j<=n;j++)
			dist[j]=edge[1][j];
		for(j=1;j<=n-2;j++)
		{
			k=2;
			while(flag[k]==1)k++;
			l=k;
			for(r=k+1;r<=n;r++)
				if(flag[r]==0&&dist[r]>dist[l])
					l=r;
			flag[l]=1;
			for(k=2;k<=n;k++)
			{
				if(flag[k]==0)
				{
			    	if(edge[l][k]<=dist[l])
			    		r=edge[l][k];
		    		else
				    	r=dist[l];
			    	if(r>dist[k])
				    	dist[k]=r;
				}
			}
		}
		printf("Scenario #%d:\n",i);
		printf("%d\n\n",dist[n]);
	}
	return 0;
}
