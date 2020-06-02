#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

#define MAX 1000000

char str[106][106],n;
int flag[106][106];
int G[206][206],ft[206][206];

int c[206][206],f[206][206],pre[206],dist[206],que[1000];
bool inque[206];

int ek(int s,int t)
{
	int i,j,k,head,tail,res=0;
	memset(f,0,sizeof(f));
	while(true)
	{
		for(i=0;i<=2*n+1;i++)
		{
			dist[i]=MAX;
		}
		dist[s]=0;
		head=tail=0;
		que[tail++]=s;
		memset(inque,0,sizeof(inque));
		inque[s]=true;
		memset(pre,-1,sizeof(pre));
		while(head<tail)
		{
			int u=que[head++];
			inque[u]=false;
			for(i=0;i<=2*n+1;i++)
			{
				if(c[u][i]>0&&dist[u]+ft[u][i]<dist[i])
				{
					dist[i]=dist[u]+ft[u][i];
					if(!inque[i])
					{
						que[tail++]=i;
						inque[i]=true;
					}
					pre[i]=u;
				}
			}
		}
		if(pre[t]==-1)
		{
			break;
		}
		res+=dist[t];
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
	return res;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,M,N,l;
	while(scanf("%d%d",&M,&N)!=EOF&&!(N==0&&M==0))
	{
		for(i=0;i<M;i++)
		{
			scanf("%s",str[i]);
		}
		memset(flag,0,sizeof(flag));
		n=0;
		for(i=0;i<M;i++)
		{
			for(j=0;j<N;j++)
			{
				if(str[i][j]=='H')
				{
					n++;
				}
			}
		}
		int mm=1,hh=n+1;
		for(i=0;i<M;i++)
		{
			for(j=0;j<N;j++)
			{
				if(str[i][j]=='m')
				{
					flag[i][j]=mm++;
				}
				else if(str[i][j]=='H')
				{
					flag[i][j]=hh++;
				}
			}
		}
		memset(G,0,sizeof(G));
		memset(ft,0,sizeof(ft));
		for(i=1;i<=n;i++)
		{
			G[0][i]=1;
			for(j=n+1;j<=2*n;j++)
			{
				G[i][j]=1;
			}
		}
		for(i=n+1;i<=2*n;i++)
		{
			G[i][2*n+1]=1;
		}
		memcpy(c,G,sizeof(G));
		for(i=0;i<M;i++)
		{
			for(j=0;j<N;j++)
			{
				if(str[i][j]=='m')
				{
					for(k=0;k<M;k++)
					{
						for(l=0;l<N;l++)
						{
							if(str[k][l]=='H')
							{
								ft[ flag[i][j] ][ flag[k][l] ]=abs(i-k)+abs(j-l);
							}
						}
					}
				}
			}
		}
		printf("%d\n",ek(0,2*n+1));
	}
	return 0;
}