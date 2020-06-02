#include<iostream>
#define Max 1000000
using namespace std;

int edge[505][505];
struct node{
	int begin,end;
	int cost;
};
struct node EDGE[250005];

int dist[505],N,cnt;

void relax(int u,int v)
{
	if(dist[u]+edge[u][v]<dist[v])
		dist[v]=dist[u]+edge[u][v];
}

bool Ford()
{
	int i,j;
	dist[1]=0;
	for(i=2;i<=N;i++)
		dist[i]=edge[1][i];
	for(i=1;i<=N-1;i++)
	{
		for(j=0;j<cnt;j++)
			relax(EDGE[j].begin,EDGE[j].end);
	}
	for(i=0;i<cnt;i++)
		if(dist[EDGE[i].begin]+edge[EDGE[i].begin][EDGE[i].end]<dist[EDGE[i].end])
			return false;
	return true;
}


int main()
{
//	freopen("in.txt","r",stdin);
	int F,M,W,S,E,T,i,j,k;
	scanf("%d",&F);
	for(i=1;i<=F;i++)
	{
		cnt=0;
		scanf("%d%d%d",&N,&M,&W);
		for(j=1;j<=N;j++)
			for(k=1;k<=N;k++)
				edge[j][k]=Max;
		for(j=1;j<=M;j++)
		{
			scanf("%d%d%d",&S,&E,&T);
			if(T<edge[S][E])
			{
				edge[S][E]=T;
			}
			else if(T<edge[E][S])
			{
				edge[E][S]=T;
			}
		}
		for(j=1;j<=W;j++)
		{
			scanf("%d%d%d",&S,&E,&T);
			if(T<edge[S][E])
			{
				edge[S][E]=-T;
			}
		}
		for(j=1;j<=N;j++)
			for(k=1;k<=N;k++)
				if(edge[j][k]!=Max)
				{
					EDGE[cnt].begin=j;
					EDGE[cnt].end=k;
					EDGE[cnt].cost=edge[j][k];
					cnt++;
				}
		if(Ford())
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
