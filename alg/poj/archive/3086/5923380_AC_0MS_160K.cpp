#include<iostream>
using namespace std;

int W[302];

int main()
{
//	freopen("in.txt","r",stdin);
	int N,n,i=1,k;
	for(k=1;k<=300;k++)
	{
		i+=k+1;
		W[k]=W[k-1]+k*i;
	}
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		scanf("%d",&n);
		printf("%d %d %d\n",i,n,W[n]);
	}
	return 0;
}