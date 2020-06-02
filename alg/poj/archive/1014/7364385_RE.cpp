#include <iostream>
#include <cstdio>

using namespace std;

#define maxf(a,b) a>b?a:b

int w[10],c[10],num[10],ff[120006],V,n;

bool mpack()
{
	int i,j,k,v;
	memset(ff,-1,sizeof(ff));
	ff[0]=0;
	for(i=1;i<=n;i++)
	{
		int mnt=num[i];
		if(mnt*c[i]>=V)
		{
			for(v=c[i];v<=V;v++)
			{
				if(ff[v-c[i]]==-1)
				{
					continue;
				}
				ff[v]=maxf(ff[v],ff[v-c[i]]+w[i]);
			}
			continue;
		}
		k=1;
		while(k<mnt)
		{
			for(v=V;v>=k*c[i];v--)
			{
				if(ff[v-k*c[i]]==-1)
				{
					continue;
				}
				ff[v]=maxf(ff[v],ff[v-k*c[i]]+k*w[i]);
			}
			k*=2;
			mnt-=k;
		}
		for(v=V;v>=mnt*c[i];v--)
		{
			if(ff[v-mnt*c[i]]==-1)
			{
				continue;
			}
			ff[v]=maxf(ff[v],ff[v-mnt*c[i]]+mnt*w[i]);
		}
	}
	return ff[V]!=-1;
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
