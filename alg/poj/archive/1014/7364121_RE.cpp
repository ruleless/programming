#include <iostream>
#include <cstdio>

using namespace std;

#define maxf(a,b) a>b?a:b

#define MAX 99999999

int w[10],c[10],num[10],f[1200000],V,n;

bool mpack()
{
	int i,j,k,v;
	for(i=1;i<=V;i++)
	{
		f[i]=-MAX;
	}
	f[0]=0;
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
			k*=2;
			mnt-=k;
		}
		for(v=V;v>=mnt*c[i];v--)
		{
			f[v]=maxf(f[v],f[v-mnt*c[i]]+mnt*w[i]);
		}
	}
	return f[V]==V;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,cse=0;
	n=6;
	for(i=1;i<=6;i++)
	{
		w[i]=i;
		c[i]=i;
	}
	while(scanf("%d%d%d%d%d%d",&num[1],&num[2],&num[3],&num[4],&num[5],&num[6]),
		num[1]+num[2]+num[3]+num[4]+num[5]+num[6])
	{
		cse++;
		k=0;
		for(i=1;i<=n;i++)
		{
			k+=num[i]*w[i];
		}
		if(k%2==0)
		{
			V=k/2;
			if(mpack())
			{
				printf("Collection #%d:\nCan be divided.\n\n",cse);
			}
			else
			{
				printf("Collection #%d:\nCan't be divided.\n\n",cse);

			}
		}
		else
		{
			printf("Collection #%d:\nCan't be divided.\n\n",cse);
		}
	}
	return 0;
}
