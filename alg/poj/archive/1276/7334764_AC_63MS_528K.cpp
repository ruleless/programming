#include <iostream>
#include <cstdio>

using namespace std;

int f[100006];
int w[15],num[15],cost[15],n,V;

int maxf(int a,int b)
{
	return a>b?a:b;
}

int mpack()
{
	memset(f,0,sizeof(f));
	int i,j,k,v;
	for(i=1;i<=n;i++)
	{
		int mnt=num[i];
		k=1;
		while(k<mnt)
		{
			for(v=V;v>=k*cost[i];v--)
			{
				f[v]=maxf(f[v],f[v-cost[i]*k]+k*w[i]);
			}
			mnt-=k;
			k*=2;
		}
		for(v=V;v>=mnt*cost[i];v--)
		{
			f[v]=maxf(f[v],f[ v-cost[i]*mnt ]+mnt*w[i]);
		}
	}
	return f[V];
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k;
	while(scanf("%d%d",&V,&n)!=EOF)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&num[i],&cost[i]);
			w[i]=cost[i];
		}
		printf("%d\n",mpack());
	}
	return 0;
}