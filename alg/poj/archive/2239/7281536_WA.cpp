#include <iostream>
#include <cstdio>

using namespace std;

bool edge[306][306];

int n;
const int m=7*12;
bool vis[100];
int pre[100];

bool Find(int a)
{
	int i,j,k;
	for(i=1;i<=m;i++)
	{
		if(edge[a][i]&&!vis[i])
		{
			vis[i]=true;
			if(pre[i]==-1||Find(pre[i]) )
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
	int i,j,k,t,p,q;
	while(scanf("%d",&n)!=EOF)
	{
		memset(edge,0,sizeof(edge));
		for(i=1;i<=n;i++)
		{
			scanf("%d",&t);
			while(t--)
			{
				scanf("%d%d",&p,&q);
				edge[i][(p-1)*7+q]=true;
			}
		}
		printf("%d\n",solve());
	}
	return 0;
}