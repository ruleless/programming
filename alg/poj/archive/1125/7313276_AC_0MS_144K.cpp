#include <iostream>
#include <cstdio>

using namespace std;

int edge[105][105],dist[105],n;
bool vis[105];
#define MAX 10000000

int dij(int s)
{
	int i,j,k;
	memset(vis,0,sizeof(vis));
	for(i=1;i<=n;i++)
	{
		dist[i]=edge[s][i];
	}
	vis[s]=true;
	for(j=1;j<=n-2;j++)
	{
		k=1;
		while(vis[k])k++;
		int beg=k;
		for(i=1;i<=n;i++)
		{
			if(!vis[i]&&dist[i]<dist[k])
			{
				k=i;
			}
		}
		vis[k]=true;
		for(i=beg;i<=n;i++)
		{
			if(!vis[i]&&dist[k]+edge[k][i]<dist[i])
			{
				dist[i]=dist[k]+edge[k][i];
			}
		}
	}
	k=0;
	for(i=1;i<=n;i++)
	{
		if(i!=s&&dist[i]>k)
		{
			k=dist[i];
		}
	}
	return k;
}

void solve()
{
	int i,j,k=MAX,ans;
	for(i=1;i<=n;i++)
	{
		j=dij(i);
		if(j<k)
		{
			k=j;
			ans=i;
		}
	}
	if(k>=MAX)
	{
		printf("disjoint\n");
	}
	else
	{
		printf("%d %d\n",ans,k);
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,x;
	while(scanf("%d",&n)!=EOF&&n)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				edge[i][j]=MAX;
			}
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			while(x--)
			{
				scanf("%d%d",&j,&k);
				edge[i][j]=k;
			}
		}
		solve();
	}
	return 0;
}