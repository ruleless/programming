#include<iostream>
using namespace std;

int a[5000],dp[5000];

int main()
{
//	freopen("in.txt","r",stdin);
	int n,i,j,k,Max,cse=0;
	while(scanf("%d",&k),k!=-1)
	{
		Max=1;
		cse++;
		n=1;
		a[n]=k;
		while(scanf("%d",&k),k!=-1)
		{
			n++;
			a[n]=k;
		}
		dp[1]=1;
		for(i=2;i<=n;i++)
		{
			k=1;
			for(j=1;j<i;j++)
				if(a[i]<=a[j]&&(dp[j]+1>k))
					k=dp[j]+1;
			dp[i]=k;
			if(dp[i]>Max)
				Max=dp[i];
		}
		printf("Test #%d:\n  maximum possible interceptions: %d\n\n",cse,Max);
	}
	return 0;
}