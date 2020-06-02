#include<iostream>
#include<limits>
using namespace std;

int max_int=numeric_limits<int>::max();

int edge[200][200],dist[200],max[200],flag[200];


void dijk(int i,int*dist,int n)
{
	memset(flag,0,sizeof(flag));
	int j,k,m,l;
	for(j=1;j<=n;j++)
		if(j!=i)
			dist[j]=edge[i][j];
	for(j=1;j<=n-2;j++)
	{
		m=1;
		while(flag[m]==1)m++;
		l=m;
		for(k=m+1;k<=n;k++)
			if(flag[k]==0&&dist[k]<dist[l]&&k!=i)
				l=k;
		flag[l]=1;
		for(k=1;k<=m;k++)
			if(flag[k]==0&&k!=i&&(edge[l][k]+dist[l])<dist[k])
			{
				dist[k]=edge[l][k]+dist[l];
			}
	}
}


int main()
{
	int n,i,j,t,l,m;
//	freopen("in.txt","r",stdin);
	while(scanf("%d",&n),n)
	{
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
		    	edge[i][j]=max_int;
		for(i=1;i<=n;i++)
		{
	    	scanf("%d",&t);
			for(j=1;j<=t;j++)
			{
				scanf("%d%d",&l,&m);
				edge[i][l]=m;
			}
		}

		for(i=1;i<=n;i++)
		{
			dijk(i,dist,n);
			j=1;
			while(i==j)j++;
			max[i]=dist[j];
			for(j=1;j<=n;j++)
				if(j!=i&&dist[j]>max[i])
					max[i]=dist[j];
		}
		j=1;
		for(i=2;i<=n;i++)
			if(max[i]<max[j])
				j=i;
		if(max[j]==max_int)
			printf("disjoint\n");
		else
			printf("%d %d\n",j,max[j]);


	}
	return 0;
}
