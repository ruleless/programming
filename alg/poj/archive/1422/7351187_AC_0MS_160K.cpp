#include <iostream>
#include <cstdio>

using namespace std;

bool edge[150][150],vis[150];
int n,link[150];

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

int solve()
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
	return k;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,t,m;
	scanf("%d",&t);
	while(t--)
	{
		memset(edge,0,sizeof(edge));
		scanf("%d%d",&n,&m);
		while(m--)
		{
			scanf("%d%d",&i,&j);
			edge[i][j]=true;
		}
		printf("%d\n",n-solve());
	}
	return 0;
}