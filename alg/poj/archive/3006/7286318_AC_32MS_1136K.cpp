#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
#define N 1000005

bool isprime[N+6];

void prime()
{
	int i,j,k;
	memset(isprime,0,sizeof(isprime));
	isprime[1]=true;
	for(i=2;i<=N;i++)
	{
		if(!isprime[i])
		{
			for(j=2;i*j<=N;j++)
			{
				isprime[i*j]=true;
			}
		}
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k;
	int a,d,n;
	prime();
	while(scanf("%d%d%d",&a,&d,&n)!=EOF&& !(a==0&&d==0&&n==0) )
	{
		k=0;
		for(i=a;;i+=d)
		{
			if(!isprime[i])
			{
				k++;
				if(k==n)
				{
					j=i;
					break;
				}
			}
		}
		printf("%d\n",j);
	}
	return 0;
}