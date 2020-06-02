#include<iostream>
#include<cmath>
#include<time.h>
using namespace std;

struct Edge
{
	int beg,end;
	double cost;
}edge[250006],point[505];
int parent[506];

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
	if( (((struct Edge*)a)->cost)<(((struct Edge*)b)->cost) )
		return -1;
	else if( (((struct Edge*)a)->cost)==(((struct Edge*)b)->cost) )
		return 0;
	return 1;
}

int main()
{
//	__int64 beg=clock();
//	freopen("in.txt","r",stdin);
	int i,j,s,n,t,cnt;
	double Max;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&s,&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&point[i].beg,&point[i].end);
		}
		cnt=0;
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
			{
				edge[cnt].beg=i;
				edge[cnt].end=j;
				edge[cnt].cost=1.0*(point[i].beg-point[j].beg)*(point[i].beg-point[j].beg)+1.0*(point[i].end-point[j].end)*(point[i].end-point[j].end);
				cnt++;
			}
		qsort(edge,cnt,sizeof(struct Edge),cmp);
		memset(parent,-1,sizeof(parent));
		j=0;
		for(i=0;i<cnt;i++)
		{
			if(Find(edge[i].beg)!=Find(edge[i].end))
			{
				Union(edge[i].beg,edge[i].end);
				j++;
				if(n-s==j)
					Max=edge[i].cost;
			}
		}
		printf("%.2lf\n",sqrt(Max));
	}
//	__int64 end=clock();
//	printf("%I64d\n",end-beg);
	return 0;
}