#include <iostream>
#include <cstdio>

using namespace std;

struct Edge
{
	int u,v,w;
}e[3000];

int n,cnt,dist[506];

#define MAX 10000000

bool bellman(int s)
{
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		dist[i]=MAX;
	}
	dist[s]=0;
	//bool flag;
	for(i=1;i<=n-1;i++)
	{
	//	flag=true;
		for(j=0;j<cnt;j++)
		{
			if(dist[e[j].u]+e[j].w<dist[e[j].v])
			{
		//		flag=false;
				dist[e[j].v]=dist[e[j].u]+e[j].w;
			}
		}
	//	if(flag)
		{
		//	return false;
		}
	}
	for(i=0;i<cnt;i++)
	{
		if(dist[e[i].u]+e[i].w<dist[e[i].v])
		{
			return true;
		}
	}
	return false;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,t,w,m;
	scanf("%d",&t);
	while(t--)
	{
		cnt=0;
		scanf("%d%d%d",&n,&m,&w);
		while(m--)
		{
			scanf("%d%d%d",&i,&j,&k);
			e[cnt].u=i;
			e[cnt].v=j;
			e[cnt++].w=k;
		}
		while(w--)
		{
			scanf("%d%d%d",&i,&j,&k);
			e[cnt].u=i;
			e[cnt].v=j;
			e[cnt++].w=-k;
		}
		if(bellman(1))
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}