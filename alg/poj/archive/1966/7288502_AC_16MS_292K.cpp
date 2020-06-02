#include <iostream>
#include <cstdio>

using namespace std;
#define MAX 1000000

int G[105][105],f[105][105],c[105][105],pre[105],que[105];
bool vis[105];
int n;

int ek(int s,int t)
{
	int i,j,k,tail,head,flow=0;
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
	int i,j,k,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(G,0,sizeof(G));
		while(m--)
		{
			scanf(" (%d,%d) ",&i,&j);
			i++;
			j++;
			G[i+n][j]=MAX;
			G[j+n][i]=MAX;
		}
		for(i=1;i<=n;i++)
		{
			G[i][i+n]=1;
		}
		int min1=1<<30;
		if(n>1)
		{
			for(i=1;i<=n;i++)
			{
				if(i!=1)
				{
					memcpy(c,G,sizeof(G));
					int temp=ek(1+n,i);
					if(temp<min1)
					{
						min1=temp;
					}
				}
			}
		}
		if(n==0)
		{
			printf("0\n");
		}
		else if(n==1)
		{
			printf("1\n");
		}
		else
		{
			if(min1>=MAX)
			{
				min1=n;
			}
			printf("%d\n",min1);
		}
	}
	return 0;
}