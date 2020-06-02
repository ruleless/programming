#include<iostream>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int n,i,sum=0;
	while(scanf("%d",&n)!=EOF)
	{
		sum=0;
		for(i=1;sum<n;i++)
			sum+=i;
		i--;
		sum-=i;
		//printf("%d %d\n",i,sum);
		if(i%2==0)
		{
			printf("TERM %d IS %d%/%d\n",n,n-sum,i+sum-n+1);
		}
		else
		{
			printf("TERM %d IS %d%/%d\n",n,i+sum-n+1,n-sum);
		}

	}
	return 0;
}