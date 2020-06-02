#include <iostream>
#include <cstdio>

using namespace std;

bool edge[520][520],n;
int link[520];
bool vis[520];

bool Find(int a)
{
	int i,j,k;
	for(i=1;i<=n;i++)
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

void solve()
{
	int i,j,k=0;
	memset(link,-1,sizeof(link));
	for(i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		if(Find(i))
		{
			k++;
		}
	}
	printf("%d\n",n-k);
}

void floyd()
{
	int i,j,k;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				edge[i][j]|=edge[i][k]&edge[k][j];
			}
		}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	int i,j,k,m;
	while(scanf("%d%d",&n,&m),n+m)
	{
		memset(edge,0,sizeof(edge));
		while(m--)
		{
			scanf("%d%d",&i,&j);
			edge[i][j]=true;
		}
		floyd();
		solve();
	}
	return 0;
}