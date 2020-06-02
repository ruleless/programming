#include <iostream>
#include <cstdio>

using namespace std;

int parent[105];
int n,m;

struct Edge
{
	int u,v,w;
}e[10006];

int Find(int x)
{
	if(parent[x]<0)
	{
		return x;
	}
	int r=Find(parent[x]);
	parent[x]=r;
	return r;
}

int cmp(const void* a,const void *b)
{
	return ( (struct Edge*)a )->w-( (struct Edge*)b )->w;
}

void Union(int x,int y)
{
	int a=Find(x);
	int b=Find(y);
	if(parent[a]<parent[b])
	{
		parent[a]+=parent[b];
		parent[b]=a;
	}
	else 
	{
		parent[b]+=parent[a];
		parent[a]=b;
	}
}

int kru(int a)
{
	int i,j,k,cnt=0;
	int low=1<<30;int high=0;
	for(i=a;i<m;i++)
	{
		if(Find(e[i].u)!=Find(e[i].v))
		{
			cnt++;
			Union(e[i].u,e[i].v);
			if(e[i].w<low)
			{
				low=e[i].w;
			}
			if(e[i].w>high)
			{
				high=e[i].w;
			}
			if(cnt==n-1)
			{
				break;
			}
		}
	}
	if(cnt<n-1)
	{
		return -1;
	}
	else
	{
		return high-low;
	}
}

void solve()
{
	qsort(e,m,sizeof(struct Edge),cmp);
	int i,j=1<<30,k;
	bool flag=false;
	for(i=0;i<m;i++)
	{
		memset(parent,-1,sizeof(parent));
		k=kru(i);
		if(k==-1)
		{
			break;
		}
		else
		{
			flag=true;
			if(k<j)
			{
				j=k;
			}
		}
	}
	if(flag)
		printf("%d\n",j);
	else
	{
		printf("-1\n");
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k;
	while(scanf("%d%d",&n,&m)!=EOF&&!(n==0&&m==0))
	{
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		}
		solve();
	}
	return 0;
}