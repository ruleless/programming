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
		printf("Scenario #%d:\n",i);
		scanf("%d%d",&n,&m);
		for(l=1;l<=n;l++)
			for(r=1;r<=n;r++)
				edge[l][r]=-1;
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
			k=1;
			while(flag[k]==1)k++;
			l=k;
			for(r=k+1;r<=n;r++)
				if(flag[r]==0&&dist[r]>dist[l])
					l=r;
			flag[l]=1;
			for(k=1;k<=n;k++)
			{
				r=(edge[l][k]<dist[l])?edge[l][k]:dist[l];
				if(flag[k]==0&&r>dist[k])
					dist[k]=r;
			}
		}
		printf("%d\n\n",dist[n]);
	}
	return 0;
}
