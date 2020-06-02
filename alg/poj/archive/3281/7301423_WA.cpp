#include <iostream>
#include <cstdio>

using namespace std;

int G[310][310];
int N,F,D;
int c[310][310],f[310][310],pre[310],que[310],head,tail;
bool vis[310];

int ek(int s,int t)
{
	int i,j,k,flow=0;
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
			for(i=0;i<=F+N+D+1;i++)
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
	int i,j,k,t;
	scanf("%d%d%d",&N,&F,&D);
	memset(G,0,sizeof(G));
	for(i=1;i<=N;i++)
	{
		scanf("%d%d",&j,&k);
		while(j--)
		{
			scanf("%d",&t);
			G[t][F+i]=1;
		}
		while(k--)
		{
			scanf("%d",&t);
			G[F+i][F+N+t]=1;
		}
	}
	for(i=1;i<=F;i++)
	{
		G[0][i]=1;
	}
	for(i=F+N+1;i<=F+N+D;i++)
	{
		G[i][F+N+D+1]=1;
	}
	memcpy(c,G,sizeof(G));
	printf("%d\n",ek(0,F+N+D+1));
	return 0;
}