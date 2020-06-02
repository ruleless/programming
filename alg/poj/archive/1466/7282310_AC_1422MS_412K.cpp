#include <iostream>
#include <cstdio>

using namespace std;

bool edge[505][505];
int n;
int pre[505];
bool vis[505];

bool Find(int a)
{
	int i,j,k;
	for(i=0;i<n;i++)
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
	for(i=0;i<n;i++)
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
	int i,j,k;
	while(scanf("%d",&n)!=EOF)
	{
		int temp;
		memset(edge,0,sizeof(edge));
		for(i=0;i<n;i++)
		{
			scanf("%d:",&temp);
			scanf(" (%d) ",&j);
			while(j--)
			{
				scanf("%d",&k);
				edge[i][k]=true;
			}
		}
		printf("%d\n",n-solve()/2);
	}
	return 0;
}