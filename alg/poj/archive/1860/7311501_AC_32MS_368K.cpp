#include <iostream>
#include <cstdio>

using namespace std;

#define eps 10e-10

double r[120][120],c[120][120],v,dist[120];
int n;

bool bellman(int s)
{
	int i,j,k;
	memset(dist,0,sizeof(dist));
	dist[s]=v;
	bool flag;
	for(k=1;k<=n-1;k++)
	{
		flag=true;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if( r[i][j]>eps&&(dist[i]-c[i][j])*r[i][j]>dist[j] )
				{
					flag=false;
					dist[j]=(dist[i]-c[i][j])*r[i][j];
				}
			}
		}
		if(flag)
		{
			if(dist[s]>v+eps)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if( (dist[i]-c[i][j])*r[i][j]>dist[j] )
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,a,b,s,m;
	scanf("%d%d%d%lf",&n,&m,&s,&v);
	memset(r,0,sizeof(r));
	while(m--)
	{
		scanf("%d%d",&a,&b);
		scanf("%lf%lf%lf%lf",&r[a][b],&c[a][b],&r[b][a],&c[b][a]);
	}
	if(bellman(s))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}