#include<iostream>
#include<cmath>
using namespace std;

struct node
{
	double x,y;
}Node[1010];

struct Edge
{
	int beg,end;
	double cost;
}edge[1000000];
int parent[1010];

int Find(int x)
{
	if(parent[x]<0)
		return x;
	int r=Find(parent[x]);
	parent[x]=r;
	return r;
}

void Union(int x,int y)
{
	int a=Find(x);
	int b=Find(y);
	parent[b]+=parent[a];
	parent[a]=b;
}

int cmp(const void* a,const void* b)
{
	if( ((struct Edge*)a)->cost<((struct Edge*)b)->cost )
		return -1;
	else if( ((struct Edge*)a)->cost>((struct Edge*)b)->cost )
		return 1;
	else 
		return 0;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int N,M,i,j,k=0;
	double sum=0;
	scanf("%d%d",&N,&M);
	for(i=1;i<=N;i++)
		scanf("%lf%lf",&Node[i].x,&Node[i].y);
	for(i=1;i<N;i++)
		for(j=i+1;j<=N;j++)
		{
			edge[k].beg=i;
			edge[k].end=j;
			edge[k].cost=sqrt( 1.0*(Node[j].y-Node[i].y)*(Node[j].y-Node[i].y)+1.0*(Node[j].x-Node[i].x)*(Node[j].x-Node[i].x) );
			k++;
		}
	qsort(edge,k,sizeof(struct Edge),cmp);
	memset(parent,-1,sizeof(parent));
	while(M--)
	{
		scanf("%d%d",&i,&j);
		Union(i,j);
	}
	for(i=0;i<k;i++)
	{
		if(Find(edge[i].beg)!=Find(edge[i].end))
		{
			Union(edge[i].beg,edge[i].end);
			sum+=edge[i].cost;
		}
	}
	printf("%.2lf\n",sum);
	return 0;
}