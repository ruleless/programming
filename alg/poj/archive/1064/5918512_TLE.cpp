#include<iostream>
using namespace std;

int aa[10000];

int main()
{
//	freopen("in.txt","r",stdin);
	int n,k,i,sum,a,b,mid;
	float temp;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%f",&temp);
		aa[i]=int(temp*100);
	}
	a=100;b=10000000;
	sum=0;
	for(i=0;i<n;i++)
	{
		sum+=int(aa[i]/a);
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
		printf("%.2lf\n",b*1.0/100);
		goto loop;
	}
	while(1)
	{
	//	printf("%d %d\n",a,b);
		
		mid=(a+b)/2;
	//	printf("%d\n",mid);
		sum=0;
		for(i=0;i<n;i++)
		{
			sum+=int(aa[i]/mid);
		}
		if(sum==k)
			break;
		else if(sum>k)
			a=mid;
		else
			b=mid;
	}
	for(;sum==k;mid++)
	{
		sum=0;
		for(i=0;i<n;i++)
		{
			sum+=int(aa[i]/mid);
		}
	}
	printf("%.2lf\n",(mid-2)*1.0/100);
loop:	return 0;
}