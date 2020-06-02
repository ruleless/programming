#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
#define eps 10e-9

bool edge[120][120];
int n,m;
struct Point
{
	double x,y;
}x[120],y[120];

int pre[120];
bool vis[120];

bool Find(int a)
{
	int i,j,k;
	for(i=1;i<=m;i++)
	{
		if(edge[a][i]&&!vis[i])
		{
			vis[i]=true;
			if(pre[i]==-1||Find(pre[i]) )
			{
				pre[i]=a;
				return true;
			}
		}
	}
	return false;
}

int solve()
{
	int i,j,k=0;
	memset(pre,-1,sizeof(pre));
	for(i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		if(Find(i))
		{
			k++;
		}
	}
	return k;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,s,v;
	while(scanf("%d%d%d%d",&n,&m,&s,&v)!=EOF)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%lf%lf",&x[i].x,&x[i].y);
		}
		for(i=1;i<=m;i++)
		{
			scanf("%lf%lf",&y[i].x,&y[i].y);
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(sqrt( (x[i].x-y[j].x)*(x[i].x-y[j].x) + (x[i].y-y[j].y)*(x[i].y-y[j].y) )/(1.0*v) <=1.0*s+eps )
				{
					edge[i][j]=true;
				}
				else
				{
					edge[i][j]=false;
				}
			}
			
		}
		printf("%d\n",n-solve());
	}
	return 0;
}