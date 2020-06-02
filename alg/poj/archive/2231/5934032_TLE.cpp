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