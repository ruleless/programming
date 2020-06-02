#include<iostream>
using namespace std;

int edge[120][120],parents[150]={0},N;

struct node{
	int begin,end;
	int cost;
};

int Find(int x)
{
	if(parents[x]==0)
		return x;
	int r=Find(parents[x]);
	parents[x]=r;
	return r;
}

void Union(int x,int y)
{
	int a=Find(x),b=Find(y);
	if(a==b)
		return;
	parents[a]=b;
}

int cmp(const void*a,const void*b)
{
	return ((node*)a)->cost-((node*)b)->cost;
}

struct node EDGE[10000];

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,n=0,k,sum=0;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
		{
			scanf("%d",&edge[i][j]);
			EDGE[n].begin=i;
			EDGE[n].end=j;
			EDGE[n].cost=edge[i][j];
			n++;
		}
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&j,&k);
		if(Find(j)!=Find(k))
			Union(j,k);
	}
	qsort(EDGE,N*N,sizeof(node),cmp);
	for(i=0;i<N*N;i++)
	{
		if(Find(EDGE[i].begin)!=Find(EDGE[i].end))
		{
			sum+=EDGE[i].cost;
			Union(EDGE[i].begin,EDGE[i].end);
		}
	}
	printf("%d\n",sum);
	return 0;
}