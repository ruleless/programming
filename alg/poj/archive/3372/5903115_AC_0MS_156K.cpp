#include<iostream>
using namespace std;

int main()
{
	int n,sum;
	while(scanf("%d",&n)!=EOF)
	{
		for(sum=1;sum<n;sum*=2);
		if(sum==n)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}