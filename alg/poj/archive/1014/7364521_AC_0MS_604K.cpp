#include <iostream>

using namespace std;

#define maxf(a,b) a>b?a:b

int num[10],ff[120006],V,n;

bool mpack()
{
	int i,j,k,v;
	memset(ff,-1,sizeof(ff));
	ff[0]=0;
	for(i=1;i<=n;i++)
	{
		int mnt=num[i];
		if(mnt*i>=V)
		{
			for(v=i;v<=V;v++)
			{
				if(ff[v-i]==-1)
				{
					continue;
				}
				ff[v]=maxf(ff[v],ff[v-i]+i);
			}
			continue;
		}
		k=1;
		while(k<mnt)
		{
			for(v=V;v>=k*i;v--)
			{
				if(ff[v-k*i]==-1)
				{
					continue;
				}
				ff[v]=maxf(ff[v],ff[v-k*i]+k*i);
			}
			mnt-=k;
			k*=2;
			
		}
		for(v=V;v>=mnt*i;v--)
		{
			if(ff[v-mnt*i]==-1)
			{
				continue;
			}
			ff[v]=maxf(ff[v],ff[v-mnt*i]+mnt*i);
		}
	}
	return ff[V]!=-1;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,cse=0;
	n=6;
	while(scanf("%d%d%d%d%d%d",&num[1],&num[2],&num[3],&num[4],&num[5],&num[6]),
		num[1]+num[2]+num[3]+num[4]+num[5]+num[6])
	{
		cse++;
		k=0;
		for(i=1;i<=n;i++)
		{
			k+=num[i]*i;
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
