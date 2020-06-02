#include<iostream>
using namespace std;

int parent[1002];

struct node
{
	int beg,end,cost;
}edge[15006],e[15006];

int cmp(const void* a,const void* b)
{
	return ((struct node*)a)->cost-((struct node*)b)->cost;
}

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
	parent[a]+=parent[b];
	parent[b]=a;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int n,m,i,cnt=0,Max=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
		scanf("%d%d%d",&edge[i].beg,&edge[i].end,&edge[i].cost);
	memset(parent,-1,sizeof(parent));
	qsort(edge,m,sizeof(struct node),cmp);
	for(i=0;i<m;i++)
	{
		if(Find(edge[i].beg)!=Find(edge[i].end))
		{
			Union(edge[i].beg,edge[i].end);
			if(edge[i].cost>Max)
				Max=edge[i].cost;
			e[cnt].beg=edge[i].beg;
			e[cnt].cost=edge[i].cost;
			e[cnt].end=edge[i].end;
			cnt++;
		}
		if(cnt==n)
			break;
	}
	printf("%d\n%d\n",Max,cnt);
	for(i=0;i<cnt;i++)
		printf("%d %d\n",e[i].beg,e[i].end);
	return 0;
}