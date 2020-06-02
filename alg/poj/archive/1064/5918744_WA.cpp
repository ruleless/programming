#include<iostream>
using namespace std;

int aa[10000];

int main()
{
//	freopen("in.txt","r",stdin);
	int n,k,i,sum,a,b,mid;
	float temp;
	while(scanf("%d%d",&n,&k)!=-1){
	for(i=0;i<n;i++)
	{
		scanf("%f",&temp);
		aa[i]=int(temp*100);
	}
	a=1;b=aa[0];
	sum=0;
	for(i=0;i<n;i++)
	{
		sum+=int(aa[i]/a);
	}
	if(sum<k)
	{
		printf("0.00\n");
		continue;
	}
	while(a!=b-1)
	{
	//	printf("%d %d\n",a,b);
		
		mid=(a+b)/2;
	//	printf("%d\n",mid);
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
	printf("%.2lf\n",(mid)*1.0/100);
	}
	return 0;
}