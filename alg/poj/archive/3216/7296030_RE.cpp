#include <iostream>
#include <cstdio>

using namespace std;
#define MAX 10000000

int f[22][22],n,m;

int p[220],start[220],end[220];
bool edge[220][220];

void floyd()
{
	int i,j,k;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(f[i][k]+f[k][j]<f[i][j])
				{
					f[i][j]=f[i][k]+f[k][j];
				}
			}
		}
	}
}

int link[220];
bool vis[220];

bool Find(int a)
{
	int i,j,k;
	for(i=1;i<=m;i++)
	{
		if(edge[a][i]&&!vis[i])
		{
			vis[i]=true;
			if(link[i]==-1||Find(link[i]))
			{
				link[i]=a;
				return true;
			}
		}
	}
	return false;
}

int solve()
{
	int i,j,k=0;
	memset(link,-1,sizeof(link));
	for(i=1;i<=m;i++)
	{
		memset(vis,0,sizeof(vis));
		if(Find(i))
		{
			k++;
		}
	}
	return k;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,t;
	while(scanf("%d%d",&n,&m)!=EOF&&!(n==0&&m==0))
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%d",&f[i][j]);
				if(f[i][j]==-1)
				{
					f[i][j]=MAX;
				}
			}
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d%d%d",&j,&k,&t);
			p[i]=j;
			start[i]=k;
			end[i]=k+t;
		}
		floyd();
		memset(edge,0,sizeof(edge));
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(end[i]+f[i][j]<=start[j])
				{
					edge[i][j]=true;
				}
			}
		}
		printf("%d\n",m-solve());
	}
	return 0;
}
