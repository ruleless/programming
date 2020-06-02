#include<iostream>
#define Max 1000000
using namespace std;

struct node{
	int begin,end;
	int cost;
};
struct node EDGE[8000];

int dist[505],N,cnt;

void relax(struct node edge)
{
	if(dist[edge.begin]+edge.cost<dist[edge.end])
		dist[edge.end]=dist[edge.begin]+edge.cost;
}

bool Ford()
{
	int i,j;
	dist[1]=0;
	for(i=2;i<=N;i++)
		dist[i]=Max;
	for(i=1;i<=N-1;i++)
	{
		for(j=0;j<cnt;j++)
			relax(EDGE[j]);
	}
	for(i=0;i<cnt;i++)
		if(dist[EDGE[i].begin]+EDGE[i].cost<dist[EDGE[i].end])
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
		for(j=1;j<=M;j++)
		{
			scanf("%d%d%d",&S,&E,&T);
			EDGE[cnt].begin=S;
			EDGE[cnt].end=E;
			EDGE[cnt].cost=T;
			cnt++;
			EDGE[cnt].begin=E;
			EDGE[cnt].end=S;
			EDGE[cnt].cost=T;
			cnt++;

		}
		for(j=1;j<=W;j++)
		{
			scanf("%d%d%d",&S,&E,&T);
			EDGE[cnt].begin=S;
			EDGE[cnt].end=E;
			EDGE[cnt].cost=-T;
			cnt++;
		}
	//	printf("%d\n",cnt);
		if(Ford())
			printf("NO\n");
		else
			printf("YES\n");
	//	printf("%d\n",dist[2]);
	}
	return 0;
}


