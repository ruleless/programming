#include<iostream>
using namespace std;


__int64 f(int n,int k)
{
	__int64 ans=1;
	__int64 temp=1;
	int i;
	for(i=1;i<=k;i++)
	{
		ans*=(n-k+i);
		if(ans%i==0)
			ans/=i;
		else
			temp*=i;
	}
//	printf("%I64d %I64d\n",ans,temp);
	return ans/temp;
}

int main()
{
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF&&!(n==0&&k==0))
	{
		if(k==0)
			printf("1\n");
		else
			printf("%I64d\n",f(n,k));
	}
	return 0;
}