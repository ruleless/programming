#include <iostream>
#include <cstdio>

using namespace std;

#define N 1000050

bool isprime[N+2];
int a[N],cnt,n;
bool is[N+2];

void prime()
{
	int i,j,k;
	memset(isprime,0,sizeof(isprime));
	isprime[1]=true;
	for(i=5;i<=N;i+=4)
	{
		if(!isprime[i])
			for(j=5;i*j<=N;j+=4)
			{
				isprime[i*j]=true;
			}
	}
}

void f()
{
	prime();
	int i,j,k;
	cnt=0;
	for(i=5;i<=N;i+=4)
	{
		if(!isprime[i])
		{
			a[cnt++]=i;
		}
	}
	memset(is,0,sizeof(is));
	for(i=0;i<cnt;i++)
	{
		for(j=i;__int64(a[i])*__int64(a[j])<=__int64(N);j++)
		{
			is[a[i]*a[j]]=true;
		}
	}
}

int main()
{
	int i,j,k;
	f();
	while(scanf("%d",&n)!=EOF&&n)
	{
		k=0;
		for(i=25;i<=n;i+=4)
		{
			if(is[i])
			{
				k++;
			}
		}
		printf("%d %d\n",n,k);
	}
	return 0;
}