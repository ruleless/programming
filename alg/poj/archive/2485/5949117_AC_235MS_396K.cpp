#include<iostream>
using namespace std;

int parent[501];

struct node
{
	int beg,end,cost;
}edge[25000];

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
	return ((struct node*)a)->cost-((struct node*)b)->cost;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int t,n,i,j,cnt,temp,sum,count;
	scanf("%d",&t);
	while(t--)
	{
		cnt=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&temp);
				if(j>i)
				{
					edge[cnt].beg=i;
					edge[cnt].end=j;
					edge[cnt].cost=temp;
					cnt++;
				}
			}
		}
		memset(parent,-1,sizeof(parent));
		sum=0;
		qsort(edge,cnt,sizeof(struct node),cmp);
		count=0;
		for(i=0;i<cnt;i++)
		{
			if(Find(edge[i].beg)!=Find(edge[i].end))
			{
				count++;
				Union(edge[i].beg,edge[i].end);
				if(edge[i].cost>sum)
				{
					sum=edge[i].cost;
				}
				if(count==n-1)
					break;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}