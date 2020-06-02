#include<iostream>
using namespace std;

int parent[120]={0},N;

struct node{
	int begin,end;
	int cost;
};
struct node edge[10005];

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
	int i,j,cnt,num,sum,n;
	char c,cc;
	while(scanf("%d",&N),N!=0)
	{	
	cnt=0;sum=0;getchar();
	for(i=1;i<N;i++)
	{
		scanf("%c%d",&c,&n);getchar();
		//printf("%c%d",c,n);
		for(j=1;j<=n;j++)
		{
			scanf("%c%d",&cc,&num);getchar();
			//printf("%c%d",cc,num);
			edge[cnt].begin=int(c-'A');
			edge[cnt].end=int(cc-'A');
			edge[cnt].cost=num;
			cnt++;
		}
	}
	qsort(edge,cnt,sizeof(node),cmp);
	for(i=1;i<=N;i++)
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
