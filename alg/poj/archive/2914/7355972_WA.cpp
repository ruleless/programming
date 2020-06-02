#include <iostream>
#include <cstdio>

using namespace std;

#define MAX 9999999

int edge[505][505];
int G[1006][1006],n,c[1006][1006],f[1006][1006];
int que[1006],pre[1006];
bool vis[1006];

int ek(int s,int t)
{
	int i,j,k,head,tail,flow=0;
	memset(f,0,sizeof(f));
	while(true)
	{
		memset(vis,0,sizeof(vis));
		head=tail=0;
		que[tail++]=s;
		vis[s]=true;
		while(head<tail)
		{
			k=que[head++];
			if(k==t)
			{
				break;
			}
			for(i=1;i<=2*n;i++)
			{
				if(c[k][i]>0&&!vis[i])
				{
					vis[i]=true;
					que[tail++]=i;
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
	int i,j,k,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(edge,0,sizeof(edge));
		while(m--)
		{
			scanf("%d%d%d",&i,&j,&k);
			i++;j++;
			edge[i][j]=edge[j][i]=k;
		}
		memset(G,0,sizeof(G));
		for(i=1;i<=n;i++)
		{
			G[i][i+n]=1;
		}
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				if(edge[i][j]>0)
				{
					G[i+n][j]=edge[i][j];
					G[j+n][i]=edge[i][j];
				}
			}
		}
		int res=1<<30;
		for(i=1;i<=n;i++)
		{
			memcpy(c,G,sizeof(G));
			j=ek(n+1,i);
			if(j<res)
			{
				res=j;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}