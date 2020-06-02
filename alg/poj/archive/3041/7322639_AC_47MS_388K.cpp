#include <iostream>
#include <cstdio>

using namespace std;

int n;
bool edge[505][505];
int link[505];
bool vis[505];

bool Find(int a)
{
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		if(!vis[i]&&edge[a][i])
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
	memset(link,-1,sizeof(link));
	int i,j,k=0;
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
	int i,j,k,m;
	scanf("%d%d",&n,&m);
	memset(edge,0,sizeof(edge));
	while(m--)
	{
		scanf("%d%d",&i,&j);
		edge[i][j]=true;
	}
	printf("%d\n",solve());
	return 0;
}