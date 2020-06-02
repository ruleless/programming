#include<iostream>
using namespace std;

float aa[10000];

int main()
{
//	freopen("in.txt","r",stdin);
	int n,k,i,sum;
	float a,b,mid;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
		scanf("%f",&aa[i]);
	a=1;b=100000;
	sum=0;
	for(i=0;i<n;i++)
	{
		sum+=int(aa[i]);
	}
	if(sum<k)
	{
		printf("0.00\n");
		goto loop;
	}
	sum=0;
	for(i=0;i<n;i++)
	{
		sum+=int(aa[i]/b);
	}
	if(sum>k)
	{
		printf("%.2f\n",b);
		goto loop;
	}
	while(b-a>.0001)
	{
	//	printf("%f %f\n",a,b);
		mid=(a+b)/2;
		sum=0;
		for(i=0;i<n;i++)
		{
			sum+=int(aa[i]/mid);
		}
		if(sum<k)
			b=mid;
		else
			a=mid;
	}
	printf("%.2f\n",mid);
loop:	return 0;
}