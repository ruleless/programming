#include<iostream>
using namespace std;

int a[100005],b[100005],c[100005];

int main()
{
//	freopen("in.txt","r",stdin);
	int n,i,j,Max,sum;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		if(a[0]>0)
		{
			sum=a[0];
			Max=a[0];
			b[0]=a[0];
		}
		else
		{
			Max=0;
			sum=0;
			b[0]=0;
		}

		
		for(i=1;i<n;i++)
		{
			if(a[i]+sum>Max)
			{
				Max=a[i]+b[i-1];
				sum=Max;
				b[i]=Max;
			}
			else if(a[i]+sum<0)
			{
				sum=0;
				b[i]=Max;
			}
			else
			{
				sum+=a[i];
				b[i]=Max;
			}
		}

		if(a[n-1]>0)
		{
			sum=a[n-1];
			Max=a[n-1];
			c[n-1]=a[n-1];
		}
		else
		{
			Max=0;
			sum=0;
			c[n-1]=0;
		}
		for(i=n-2;i>=0;i--)
		{
			if(sum+a[i]>Max)
			{
				Max=sum+a[i];
				c[i]=Max;
				sum=Max;
			}
			else if(sum+a[i]<0)
			{
				c[i]=Max;
				sum=0;
			}
			else
			{
				sum+=a[i];
				c[i]=Max;
			}
		}
		Max=b[0]+c[1];
		for(i=1;i<n-1;i++)
			if(b[i]+c[i+1]>Max)
				Max=b[i]+c[i+1];
		printf("%d\n",Max);
	}
	return 0;
}
