#include<iostream>
using namespace std;

__int64 a[10002];

int main()
{
//	freopen("in.txt","r",stdin);
	__int64 N,i,j,sum=0;
	scanf("%I64d",&N);
	for(i=0;i<N;i++)
		scanf("%I64d",&a[i]);
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(i!=j)
			{
				sum+=( (a[i]>a[j])?(a[i]-a[j]):(a[j]-a[i]) );
			}
		}
	}
	printf("%I64d\n",sum);
	return 0;
}