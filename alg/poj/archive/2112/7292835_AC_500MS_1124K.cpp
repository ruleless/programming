#include <iostream>
#include <cstdio>

using namespace std;
#define MAX 1000000

int f[250][250],K,C,M;
int G[250][250],ff[250][250],c[250][250],pre[250],que[250];
bool vis[250];

int ek(int s,int t)
{
	int i,j,k,flow=0;
	memset(ff,0,sizeof(ff));
	while(true)
	{
		memset(vis,0,sizeof(vis));
		int head=0,tail=0;
		que[tail++]=s;
		vis[s]=true;
		while(head<tail)
		{
			k=que[head++];
			if(k==t)
			{
				break;
			}
			for(i=0;i<=K+C+1;i++)
			{
				if(c[k][i]>0&&!vis[i])
				{
					que[tail++]=i;
					vis[i]=true;
					pre[i]=k;
				}
			}
		}
		if(k!=t)
		{
			break;
		}
		int min1=1<<30;
		j=t;
		i=pre[j];
		while(j!=s)
		{
			if(c[i][j]<min1)
			{
				min1=c[i][j];
			}
			j=i;
			i=pre[j];
		}
		flow+=min1;
		j=t;
		i=pre[j];
		while(j!=s)
		{
			ff[i][j]+=min1;
			ff[j][i]=-ff[i][j];
			c[i][j]=G[i][j]-ff[i][j];
			c[j][i]=G[j][i]-ff[j][i];
			j=i;
			i=pre[j];
		}
	}
	return flow;
}

bool check(int dis)
{
	int i,j,k;
	memset(G,0,sizeof(G));
	for(i=1;i<=K;i++)
	{
		G[0][i]=M;
	}
	for(i=K+1;i<=K+C;i++)
	{
		G[i][K+C+1]=1;
	}
	for(i=1;i<=K;i++)
	{
		for(j=K+1;j<=K+C;j++)
		{
			if(f[i][j]<=dis)
			{
				G[i][j]=1;
			}
		}
	}
	memcpy(c,G,sizeof(G));
	if(ek(0,K+C+1)>=C)
	{
		return true;
	}
	return false;
}

int solve()
{
	int i,j,k,low=0,high=0;
	for(i=1;i<=K;i++)
	{
		for(j=K+1;j<=K+C;j++)
		{
			if(f[i][j]>high)
			{
				high=f[i][j];
			}
		}
	}
	while(low<high)
	{
		int mid=(low+high)/2;
		if(check(mid))
		{
			high=mid;
		}
		else
		{
			low=mid+1;
		}
	}
	return low;
}

void floyd()
{
	int i,j,k;
	for(k=1;k<=K+C;k++)
	{
		for(i=1;i<=K+C;i++)
		{
			for(j=1;j<=K+C;j++)
			{
				if(f[i][k]+f[k][j]<f[i][j])
				{
					f[i][j]=f[i][k]+f[k][j];
				}
			}
		}
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,l;
	scanf("%d%d%d",&K,&C,&M);
	for(i=1;i<=K+C;i++)
	{
		for(j=1;j<=K+C;j++)
		{
			scanf("%d",&l);
			if(l==0)
			{
				f[i][j]=MAX;
			}
			else
			{
				f[i][j]=l;
			}
		}
	}
	floyd();
	printf("%d\n",solve());
	return 0;
}
