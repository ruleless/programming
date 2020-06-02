#include <iostream>
#include <cstdio>

using namespace std;

struct Edge
{
	int u,v,w;
}e[500000];

int Max,Min,cnt,dist[50006];

int bellman()
{
	int i,j,k;
	memset(dist,0,sizeof(dist));
	dist[Min]=0;
	for(j=0;j<Max-Min;j++)
	{
		bool flag=true;
		for(i=0;i<cnt;i++)
		{
			if(dist[e[i].u]+e[i].w>dist[e[i].v])
			{
				flag=false;
				dist[e[i].v]=dist[e[i].u]+e[i].w;
			}
		}
		for(i=Min;i<Max;i++)
		{
			if(dist[i+1]<dist[i])
			{
				flag=false;
				dist[i+1]=dist[i];
			}
		}
		for(i=Max;i>Min;i--)
		{
			if(dist[i-1]<dist[i]-1)
			{
				flag=false;
				dist[i-1]=dist[i]-1;
			}
		}
		if(flag)
		{
			return dist[Max];
		}
	}
	return dist[Max];
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,n;
	scanf("%d",&n);
	Min=1<<30;
	cnt=0;
	Max=0;
	while(n--)
	{
		scanf("%d%d%d",&i,&j,&k);
		j++;
		if(i<Min)
		{
			Min=i;
		}
		if(j>Max)
		{
			Max=j;
		}
		e[cnt].u=i;
		e[cnt].v=j;
		e[cnt++].w=k;
	}
	printf("%d\n",bellman());
	return 0;
}