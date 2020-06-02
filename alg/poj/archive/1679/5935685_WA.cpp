#include<iostream>
using namespace std;

struct node
{
	int beg,end,cost;
}edge[10002];

int e[10002];

bool visited[10002];

int parent[102];

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
//	freopen("in.txt","r",stdin);
	int n,m,i,j,t,sum,cnt,s;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++)
			scanf("%d%d%d",&edge[i].beg,&edge[i].end,&edge[i].cost);
		qsort(edge,m,sizeof(struct node),cmp);
		sum=0;
		cnt=0;
		memset(parent,-1,sizeof(parent));
		for(i=0;i<m;i++)
		{
			if(Find(edge[i].beg)!=Find(edge[i].end))
			{
				e[cnt]=i;
				cnt++;
				sum+=edge[i].cost;
				Union(edge[i].beg,edge[i].end);
			}
		}
		for(i=0;i<cnt;i++)
		{
			memset(visited,0,sizeof(visited));
			memset(parent,-1,sizeof(parent));
			visited[e[i]]=true;
			s=0;
			for(j=0;j<m;j++)
			{
				if(!visited[j]&&Find(edge[j].beg)!=Find(edge[j].end))
				{
					s+=edge[j].cost;
					Union(edge[j].beg,edge[j].end);
				}
			}
			if(s==sum)
			{
				printf("Not Unique!\n");
				break;
			}
		}
		if(i==cnt)
			printf("%d\n",sum);
	}
	return 0;
}