#include<iostream>
using namespace std;

struct Node
{
	int beg,end;
}node[50005],res[50005];

int n,cnt;

int cmp(const void * a,const void* b)
{
	if(((struct Node*)a)->beg==((struct Node*)b)->beg)
		return ((struct Node*)a)->end-((struct Node*)b)->end;
	return ((struct Node*)a)->beg-((struct Node*)b)->beg;
}

void work()
{
	int i,j;
	res[cnt].beg=node[0].beg;
	j=node[0].end;
	for(i=1;i<n;i++)
	{
		if(node[i].beg>node[i-1].end)
		{
			res[cnt++].end=node[i-1].end;
			res[cnt].beg=node[i].beg;
		}
		if(node[i].end>j)
				j=node[i].end;
	}
	res[cnt++].end=node[i-1].end>j?node[i-1].end:j;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&node[i].beg,&node[i].end);
	}
	qsort(node,n,sizeof(struct Node),cmp);
	cnt=0;
	work();
	for(i=0;i<cnt;i++)
	{
		printf("%d %d\n",res[i].beg,res[i].end);
	}
	return 0;
}