#include <iostream>
#include <cstdio>

using namespace std;

int N,F,D,G[306][306];
int c[306][306],pre[306],f[306][306],que[500];
bool vis[306];

int ek(int s,int t)
{
	int i,j,k,flow=0;
	memset(f,0,sizeof(f));
	while(true)
	{
		int head=0,tail=0;
		memset(vis,0,sizeof(vis));
		que[tail++]=s;
		vis[s]=true;
		memset(pre,-1,sizeof(pre));
		while(head<tail)
		{
			k=que[head++];
			if(k==t)
			{
				break;
			}
			for(i=0;i<=F+D+N+1;i++)
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
		j=t;
		i=pre[j];
		int min1=1<<30;
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
	int i,j,k,l;
	scanf("%d%d%d",&N,&F,&D);
	memset(G,0,sizeof(G));
	for(i=1;i<=N;i++)
	{
		scanf("%d%d",&j,&k);
		while(j--)
		{
			scanf("%d",&l);
			G[l][F+i]=1;
		}
		while(k--)
		{
			scanf("%d",&l);
			G[i+F][F+N+l]=1;
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
	printf("%d\n",ek(0,F+D+N+1));
	return 0;
}