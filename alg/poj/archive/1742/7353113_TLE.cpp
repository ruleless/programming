#include <iostream>
#include <cstdio>

using namespace std;

int c[150],num[150],f[100006],n,V;
bool flag[100006];

int maxf(int a,int b)
{
	return a>b?a:b;
}

void mpack()
{
	int i,j,k,v,res=0;
	memset(f,0,sizeof(f));
	memset(flag,0,sizeof(flag));
	for(i=1;i<=n;i++)
	{
		int mnt=num[i];
		if(mnt*c[i]>=V)
		{
			for(v=c[i];v<=V;v++)
			{
				f[v]=maxf(f[v],f[v-c[i]]+c[i]);
				if(!flag[f[v]])
				{
					flag[f[v]]=true;
					res++;
				}
			}
		}
		k=1;
		while(k<mnt)
		{
			for(v=V;v>=k*c[i];v--)
			{
				f[v]=maxf(f[v],f[v-k*c[i]]+k*c[i]);
				if(!flag[f[v]])
				{
					flag[f[v]]=true;
					res++;
				}
			}
			mnt-=k;
			k*=2;
		}
		for(v=V;v>=mnt*c[i];v--)
		{
			f[v]=maxf(f[v],f[v-mnt*c[i]]+mnt*c[i]);
			if(!flag[f[v]])
			{
				flag[f[v]]=true;
				res++;
			}
		}
	}
	printf("%d\n",res);
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k;
	while(scanf("%d%d",&n,&V)!=EOF&&!( n==0&&V==0 ) )
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&c[i]);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&num[i]);
		}
		mpack();
	}
	return 0;
}
