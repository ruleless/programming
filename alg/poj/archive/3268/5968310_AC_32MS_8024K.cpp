#include<iostream>
using namespace std;
#define inf 10000000


int edge1[1002][1002],edge2[1002][1002];
int dist1[1002],dist2[1002];
bool flag[1002];
int x,n;

void dijk1()
{
	int i,j,Min;
	memset(flag,0,sizeof(flag));
	for(i=1;i<=n;i++)
	{
		dist1[i]=edge1[x][i];
	}
	flag[x]=true;
	for(i=1;i<=n-2;i++)
	{
		for(Min=1;flag[Min]==true;Min++);
		for(j=Min+1;j<=n;j++)
		{
			if(!flag[j])
			{
				if(dist1[j]<dist1[Min])
					Min=j;
			}
		}
		flag[Min]=true;
		for(j=1;j<=n;j++)
		{
			if(!flag[j])
			{
				if(edge1[Min][j]+dist1[Min]<dist1[j])
				{
					dist1[j]=edge1[Min][j]+dist1[Min];
				}
			}
		}
	}
}

void dijk2()
{
	int i,j,Min;
	memset(flag,0,sizeof(flag));
	for(i=1;i<=n;i++)
	{
		dist2[i]=edge2[x][i];
	}
	flag[x]=true;
	for(i=1;i<=n-2;i++)
	{
		for(Min=1;flag[Min]==true;Min++);
		for(j=Min+1;j<=n;j++)
		{
			if(!flag[j])
			{
				if(dist2[j]<dist2[Min])
					Min=j;
			}
		}
		flag[Min]=true;
		for(j=1;j<=n;j++)
		{
			if(!flag[j])
			{
				if(edge2[Min][j]+dist2[Min]<dist2[j])
				{
					dist2[j]=edge2[Min][j]+dist2[Min];
				}
			}
		}
	}
}


int main()
{
//	freopen("in.txt","r",stdin);
	int m,i,j,k,Max=0;
	scanf("%d%d%d",&n,&m,&x);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			if(i==j)
			{
				edge1[i][j]=0;
				edge2[i][j]=0;
			}
			else
			{
				edge1[i][j]=inf;
				edge2[i][j]=inf;
			}
		}
	while(m--)
	{
		scanf("%d%d%d",&i,&j,&k);
		edge1[i][j]=k;
		edge2[j][i]=k;
	}
	dijk1();
	dijk2();
	for(i=1;i<=n;i++)
		if(i!=x)
		{
			if(dist1[i]+dist2[i]>Max)
				Max=dist1[i]+dist2[i];
		}
	printf("%d\n",Max);
	return 0;
}