#include<iostream>
using namespace std;

int a[1002],dp[1002];

int main()
{
//	freopen("in.txt","r",stdin);
	int n,i,j,Max=0,sum=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dp[1]=1;
	for(i=2;i<=n;i++)
	{
		Max=1;
		for(j=1;j<i;j++)
			if(a[i]>a[j]&&dp[j]+1>Max)
			{
				Max=dp[j]+1;
			}
		dp[i]=Max;
		if(dp[i]>sum)
			sum=dp[i];
	}
	printf("%d\n",sum);
	return 0;
}
