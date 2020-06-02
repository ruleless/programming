#include <iostream>
#include <cstdio>

using namespace std;

bool edge[105][105];
int n,m;
bool vis[106];
int pre[106];

bool Find(int a)
{
	int i,j,k;
	for(i=1;i<m;i++)
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
	for(i=1;i<n;i++)
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
	//freopen("in.txt","r",stdin);
	int i,j,k,x,y;
	while(scanf("%d",&n)!=EOF&&n)
	{
		scanf("%d%d",&m,&k);
		memset(edge,0,sizeof(edge));
		while(k--)
		{
			scanf("%d%d%d",&i,&x,&y);
			edge[x][y]=true;
		}
		printf("%d\n",solve());
	}
	return 0;
}
