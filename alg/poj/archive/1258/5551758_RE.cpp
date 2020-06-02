#include<iostream>
using namespace std;

int parent[120]={0},N;

struct node{
	int begin,end;
	int cost;
};
struct node edge[10000];

int cmp(const void*a,const void*b)
{
	return ((node*)a)->cost-((node*)b)->cost;
}

int Find(int x)
{
	if(parent[x]==0)
		return x;
	int r=Find(parent[x]);
	parent[x]=r;
	return r;
}

void Union(int x,int y)
{	
	int a=Find(x),b=Find(y);
	if(a==b)
		return;
	parent[a]=b;
}


int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,cnt,num,sum;
	while(scanf("%d",&N)!=EOF)
	{	
	cnt=0;sum=0;
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
		{
			scanf("%d",&num);
			edge[cnt].begin=i;
			edge[cnt].end=j;
			edge[cnt].cost=num;
			cnt++;
		}
	qsort(edge,cnt,sizeof(node),cmp);
	for(i=1;i<=cnt;i++)
		parent[i]=0;
	
	for(i=0;i<cnt;i++)
	{
		if(Find(edge[i].begin)!=Find(edge[i].end))
		{
			sum+=edge[i].cost;
			Union(edge[i].begin,edge[i].end);
		}
	}
	printf("%d\n",sum);
	}
	return 0;
}
