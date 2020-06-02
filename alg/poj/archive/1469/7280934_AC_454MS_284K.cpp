#include <iostream>
#include <cstdio>

using namespace std;

bool edge[350][350];
int p,n;
bool vis[350];
int pre[350];

bool Find(int a)
{
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		if(edge[a][i]&&!vis[i])
		{
			vis[i]=true;
			if(pre[i]==-1||Find(pre[i]))
			{
				pre[i]=a;
				return true;
			}
		}
	}
	return false;
}

int solve()
{
	int i,j,k=0;
	memset(pre,-1,sizeof(pre));
	for(i=1;i<=p;i++)
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
	scanf("%d",&t);
	while(t--)
	{
		memset(edge,0,sizeof(edge));
		scanf("%d%d",&p,&n);
		for(i=1;i<=p;i++)
		{
			scanf("%d",&j);
			while(j--)
			{
				scanf("%d",&k);
				edge[i][k]=true;
			}
		}
		if(solve()==p)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}