#include <iostream>
#include <cstdio>

using namespace std;

int G[120][120],n;
int c[120][120],f[120][120],que[120],pre[120];
bool vis[120];

int ek(int s,int t)
{
	int i,j,k,flow=0;
	memset(f,0,sizeof(f));
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
			for(i=0;i<=n+1;i++)
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
	int i,j,k,m,p,cc;
	int u,v,w;
	while(scanf("%d%d%d%d",&n,&p,&cc,&m)!=EOF)
	{
		memset(G,0,sizeof(G));
		while(m--)
		{
			scanf(" (%d,%d)%d ",&i,&j,&k);
			G[++i][++j]=k;
		}
		while(p--)
		{
			scanf(" (%d)%d ",&i,&j);
			G[0][++i]=j;
		}
		while(cc--)
		{
			scanf(" (%d)%d ",&i,&j);
			G[++i][n+1]=j;
		}
		memcpy(c,G,sizeof(G));
		printf("%d\n",ek(0,n+1));
	}
	return 0;
}