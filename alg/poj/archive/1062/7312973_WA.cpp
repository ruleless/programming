#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int l;
int rank[105],edge[105][105],dist[105],n;
bool vis[105];

#define MAX 90000000

struct Node
{
	int u,d;
	bool operator<(const struct Node a)const
	{
		return d>a.d;
	}
}t1,t2;

priority_queue<struct Node>que;

int dij(int low,int high)
{
	int i,j,k;
	while(!que.empty())
	{
		que.pop();
	}
	memset(vis,0,sizeof(vis));
	for(i=1;i<=n+1;i++)
	{
		dist[i]=MAX;
	}
	dist[1]=0;
	t1.u=1;t1.d=0;
	que.push(t1);
	while(!que.empty())
	{
		t1=que.top();
		
		que.pop();
		int u=t1.u;
		if(vis[u])
		{
			continue;
		}
		//printf("%d %d %d\n",t1.u,t1.d,vis[t1.u]);
		vis[u]=true;
		if(u==n+1)
		{
		//	printf("%d\n",dist[u]);
			return dist[u];
		}
		for(i=1;i<=n+1;i++)
		{
			if(!vis[i]&&dist[u]+edge[u][i]<dist[i]&&( ( rank[i]>=low&&rank[i]<=high )||i==n+1 ))
			{
				dist[i]=dist[u]+edge[u][i];
				t2.u=i;
				t2.d=dist[i];
				que.push(t2);
			}
		}
	}
	return MAX;
}

void solve()
{
	int i,j,k=1<<20;
	for(i=0;i<=l;i++)
	{
		j=dij(rank[1]-i,rank[1]-i+l);
		if(j<k)
		{
			k=j;
		}
	}
	printf("%d\n",j);
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,x;
	scanf("%d%d",&l,&n);
	for(i=1;i<=n+1;i++)
	{
		for(j=1;j<=n+1;j++)
		{
			edge[i][j]=MAX;
		}
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&edge[i][n+1],&rank[i],&x);
		while(x--)
		{
			scanf("%d%d",&j,&k);
			edge[i][j]=k;
		}
	}
	solve();
	return 0;
}