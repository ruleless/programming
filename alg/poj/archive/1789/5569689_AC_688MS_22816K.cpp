#include<iostream>
using namespace std;

struct node{
	int begin,end;
	int cost;
};

struct node edge[4000006];
char str[2006][9];
int parent[2006];

int len(char*p,char*q)
{
	int cnt=0,i;
	for(i=0;i<=6;i++)
		if(p[i]!=q[i])
			cnt++;
	return cnt;
}

int cmp(const void*a,const void*b)
{
	return ((node*)a)->cost-((node*)b)->cost;
}

int find(int x)
{
	if(parent[x]==-1)
		return x;
	int r=find(parent[x]);
	parent[x]=r;
	return r;
}

void Union(int x,int y)
{
	int a=find(x),b=find(y);
	if(a==b)
		return;
	parent[a]=b;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int N,i,j,cnt,Q;
	while(scanf("%d",&N),N)
	{
		memset(parent,-1,sizeof(parent));
		Q=0;
		cnt=0;
		for(i=0;i<N;i++)
			scanf("%s",str[i]);
		for(i=0;i<N-1;i++)
			for(j=i+1;j<N;j++)
			{
				edge[cnt].begin=i;
				edge[cnt].end=j;
				edge[cnt].cost=len(str[i],str[j]);
				cnt++;
			}
		qsort(edge,cnt,sizeof(node),cmp);
		for(i=0;i<cnt;i++)
		{
			if(find(edge[i].begin)!=find(edge[i].end))
			{
				Union(edge[i].begin,edge[i].end);
				Q+=edge[i].cost;
			}
		}
		printf("The highest possible quality is 1/%d.\n",Q);

	}
	return 0;
}