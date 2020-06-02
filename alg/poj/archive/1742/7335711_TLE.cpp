#include <iostream>
#include <cstdio>

using namespace std;

int w[150],c[150],num[150],f[100006],n,V;
bool flag[100006];

int maxf(int a,int b)
{
	return a>b?a:b;
}

void mpack()
{
	int i,j,k,v;
	memset(f,0,sizeof(f));
	for(i=1;i<=n;i++)
	{
		int mnt=num[i];
		if(mnt*c[i]>=V)
		{
			for(v=c[i];v<=V;v++)
			{
				f[v]=maxf(f[v],f[v-c[i]]+w[i]);
			}
		}
		k=1;
		while(k<mnt)
		{
			for(v=V;v>=k*c[i];v--)
			{
				f[v]=maxf(f[v],f[v-k*c[i]]+k*w[i]);
			}
			mnt-=k;
			k*=2;
		}
		for(v=V;v>=mnt*c[i];v--)
		{
			f[v]=maxf(f[v],f[v-mnt*c[i]]+mnt*w[i]);
		}
	}
	k=0;
	memset(flag,0,sizeof(flag));
	for(i=1;i<=V;i++)
	{
	//	printf("%d ",f[i]);
		if(!flag[f[i]])
		{
			flag[f[i]]=true;
			k++;
		}
	}
	printf("%d\n",k);
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k;
	while(scanf("%d%d",&n,&V)!=EOF&&!( n==0&&V==0 ) )
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&w[i]);
			c[i]=w[i];
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&num[i]);
		}
		mpack();
	}
	return 0;
}