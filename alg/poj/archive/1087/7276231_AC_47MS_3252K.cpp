#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <cstring>

using namespace std;
#define MAX 100000
int cnt;
int G[505][505];

int c[505][505],f[505][505],pre[505],que[505];
bool vis[505];

int ek(int s,int t)
{
	int i,j,k,flow=0;
	memset(f,0,sizeof(f));
	while(true)
	{
		int head=0,tail=0;
		que[tail++]=s;
		memset(vis,0,sizeof(vis));
		vis[s]=true;
		while(head<tail)
		{
			k=que[head++];
			if(k==t)
			{
				break;
			}
			for(i=0;i<=cnt+1;i++)
			{
				if(!vis[i]&&c[k][i]>0)
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
			f[i][j]+=min1;
			f[j][i]=-f[i][j];
			c[i][j]=G[i][j]-f[i][j];
			c[j][i]=G[j][i]-f[j][i];
			j=i;
			i=pre[j];
		}
	}
	return flow;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,n,m;
	string dev,plug,A,B;
	string ss[106];
	map<string,int>Map;
	cnt=0;
	scanf("%d",&m);
	memset(G,0,sizeof(G));
	while(m--)
	{
		cin>>plug;
		Map[plug]=++cnt;
		G[0][cnt]=1;
	}
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		cin>>dev>>plug;
		ss[i]=dev;
		Map[dev]=++cnt;
		if(Map.find(plug)==Map.end())
		{
			Map[plug]=++cnt;
			//G[0][cnt]=1;
		}
		G[ Map[plug] ][ Map[dev] ]=1;
	}
	scanf("%d",&m);
	while(m--)
	{
		cin>>B>>A;
		if(Map.find(B)==Map.end())
		{
			Map[B]=++cnt;
			//G[0][cnt]=1;
		}
		if(Map.find(A)==Map.end())
		{
			Map[A]=++cnt;
			//G[0][cnt]=1;
		}
		G[ Map[A] ][ Map[B] ]=MAX;
	}
	for(i=0;i<n;i++)
	{
		G[ Map[ss[i]] ][cnt+1]=1;
	}
	memcpy(c,G,sizeof(G));
	printf("%d\n",n-ek(0,cnt+1));
	return 0;
}