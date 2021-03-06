#include <iostream>
#include <cstdio>

using namespace std;
#define eps 10e-10
#define MAX 10e20

double G[106][106];
int m,n;
double c[106][106],f[106][106];
bool vis[106];
int que[106],head,tail,pre[106];

void ek(int s,int t)
{
	int i,j,k;
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
			for(i=0;i<=m+n+1;i++)
			{
				if(c[k][i]>eps&&!vis[i])
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
		j=t;
		i=pre[j];
		double min1=MAX;
		while(j!=s)
		{
			if(c[i][j]<min1)
			{
				min1=c[i][j];
			}
			j=i;
			i=pre[j];
		}
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
}

void dfs(int u)
{
	int i,j,k;
	for(i=0;i<=m+n+1;i++)
	{
		if(c[u][i]>eps&&!vis[i])
		{
			vis[i]=true;
			dfs(i);
		}
	}
}

double solve()
{
	int i,j,k;
	ek(0,m+n+1);
	memset(vis,0,sizeof(vis));
	vis[0]=true;
	dfs(0);
	double flow=1;
	for(i=1;i<=m;i++)
	{
	//	printf("%d %d\n",i,vis[i]);
		if(vis[0]!=vis[i])
		{
		//	printf("%d %d %d\n",i,vis[0],vis[i]);
			flow*=G[0][i];
		}
	}
	for(i=m+1;i<=m+n;i++)
	{
		if(vis[m+n+1]!=vis[i])
		{
			//printf("%d %d\n",i,vis[i]);
			flow*=G[i][m+n+1];
		}
	}
	return flow;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,t,l;
	double temp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&m,&n,&l);
		memset(G,0,sizeof(G));
		for(i=1;i<=m;i++)
		{
			scanf("%lf",&temp);
			G[0][i]=temp;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lf",&temp);
			G[i+m][m+n+1]=temp;
		}
		while(l--)
		{
			scanf("%d%d",&i,&j);
			G[i][m+j]=MAX;
		}
		memcpy(c,G,sizeof(G));
		printf("%.4lf\n",solve());
	}
	return 0;
}