#include<iostream>
using namespace std;

double aa[10000];

int main()
{
//	freopen("in.txt","r",stdin);
	int n,k,i,sum;
	double a,b,mid;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
		scanf("%lf",&aa[i]);
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
		printf("%.2lf\n",b);
		goto loop;
	}
	while(b-a>1e-11)
	{
	//	printf("%.7lf %.7lf\n",a,b);
		
		mid=(a+b)/2;
	//	printf("%.7lf\n",mid);
		sum=0;
		for(i=0;i<n;i++)
		{
			sum+=int(aa[i]/mid);
		}
		if(sum>=k)
			a=mid;
		else
			b=mid;
	}
	printf("%.2lf\n",mid-0.005);
loop:	return 0;
}