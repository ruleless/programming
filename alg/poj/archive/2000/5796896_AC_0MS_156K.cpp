#include<iostream>
using namespace std;

int main()
{
	int N,n,i,t;
	while(scanf("%d",&N)!=EOF&&N)
	{
		for(n=1;N-n*(n+1)/2>n+1;n++);
		t=0;
		for(i=1;i<=n;i++)
			t+=i*i;
		for(i=1;i<=N-n*(n+1)/2;i++)
			t+=(n+1);
		printf("%d %d\n",N,t);
	}
	return 0;
}