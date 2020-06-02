#include <iostream>
#include <cstdio>

using namespace std;

#define maxf(a,b) a>b?a:b;

int f[50000],n;

struct Node
{
	int w,c,num,a;
}node[405];

int mpack()
{
	int i,j,k,V,v,res=0;
	memset(f,0,sizeof(f));
	for(i=1;i<=n;i++)
	{
		int mnt=node[i].num;
		if(mnt*node[i].c>=node[i].a)
		{
			for(v=node[i].c;v<=node[i].a;v++)
			{
				f[v]=maxf(f[v],f[v-node[i].c]+node[i].w);
				if(f[v]>res)
				{
					res=f[v];
				}
			}
			continue;
		}
		k=1;
		while(k<mnt)
		{
			for(v=node[i].a;v>=k*node[i].c;v--)
			{
				f[v]=maxf(f[v],f[v-k*node[i].c]+k*node[i].w);
				if(f[v]>res)
				{
					res=f[v];
				}
			}
			mnt-=k;
			k*=2;
		}
		for(v=node[i].a;v>=mnt*node[i].c;v--)
		{
			f[v]=maxf(f[v],f[v-mnt*node[i].c]+mnt*node[i].w);
			if(f[v]>res)
			{
				res=f[v];
			}
		}
	}
	return res;
}

int cmp(const void *a,const void* b)
{
	return ((struct Node*)a)->a-((struct Node*)b)->a;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&node[i].w,&node[i].a,&node[i].num);
		node[i].c=node[i].w;
	}
	qsort(node+1,n,sizeof(struct Node),cmp);
	printf("%d\n",mpack());
	return 0;
}