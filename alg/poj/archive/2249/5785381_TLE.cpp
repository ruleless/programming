#include<iostream>
using namespace std;

__int64 f(__int64 n,__int64 k)
{
	__int64 i,t=1,m=1;
	for(i=1;i<=k;i++)
		t*=i;
	for(i=n-k+1;i<=n;i++)
		m*=i;
	return m/t;
}

int main()
{
	__int64 n,k;
	while(scanf("%I64d%I64d",&n,&k)!=EOF&&!(n==0&&k==0))
	{
		printf("%I64d\n",f(n,k));
	}
	return 0;
}