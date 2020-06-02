#include<iostream>
using namespace std;

int a[10002];

int main()
{
//	freopen("in.txt","r",stdin);
	int N,i,j;
	__int64 sum=0;
	scanf("%d",&N);
	for(i=0;i<N;i++)
		scanf("%d",&a[i]);
	for(i=0;i<N;i++)
	{
		for(j=i+1;j<N;j++)
		{
			sum+=( (a[i]>a[j])?(a[i]-a[j]):(a[j]-a[i]) );
		}
	}
	printf("%I64d\n",2*sum);
	return 0;
}