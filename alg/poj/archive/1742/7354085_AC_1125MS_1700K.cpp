#include <iostream>
#include <cstdio>

using namespace std;

int w[105],num[105],vis[100006],n,V,dp[100006][3];

void solve()
{
	int i,j,k=0;
	memset(vis,0,sizeof(vis));
	memset(dp,0,sizeof(dp));
	vis[0]=true;
	for(i=1;i<=n;i++)
	{
		for(j=w[i];j<=V;j++)
		{
			if(!vis[j])
			{
				if(vis[j-w[i]]==true&&!(dp[j-w[i]][0]==i&&dp[j-w[i]][1]==num[i]))
				{
					k++;
					vis[j]=true;
					dp[j][0]=i;
					if(dp[j-w[i]][0]!=i)
					{
						dp[j][1]=1;
					}
					else
					{
						dp[j][1]=dp[j-w[i]][1]+1;
					}
				}
			}
		}
	}
	printf("%d\n",k);
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k;
	while(scanf("%d%d",&n,&V),n+V)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&w[i]);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&num[i]);
		}
		solve();
	}
	return 0;
}
