#include<iostream>
using namespace std;

struct node
{
	int beg,end,cost;
}edge[10003];

int parent[2003];

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
	return ((struct node*)a)->cost-((struct node*)a)->cost;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int n,m,i,j,sum=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
		scanf("%d%d%d",&edge[i].beg,&edge[i].end,&edge[i].cost);
	qsort(edge,m,sizeof(struct node),cmp);
	j=0;
	memset(parent,-1,sizeof(parent));
	for(i=0;i<m;i++)
	{
		if(Find(edge[i].beg)!=Find(edge[i].end))
		{
			Union(edge[i].beg,edge[i].end);
			sum=edge[i].cost;
			j++;
		}
		if(j==n-1)
			break;
	}
	printf("%d\n",sum);
	return 0;
}