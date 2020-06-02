#include<iostream>
using namespace std;

int a[100005],b[100005],b1[100005],c[100005],c1[100005];

int main()
{
//	freopen("in.txt","r",stdin);
	int n,i,Max;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		b[0]=a[0];b1[0]=a[0];
		c[n-1]=a[n-1];c1[n-1]=a[n-1];
		for(i=1;i<n;i++)
		{
			if(b[i-1]>0)
				b[i]=a[i]+b[i-1];
			else
				b[i]=a[i];

			if(b[i]>b1[i-1])
				b1[i]=b[i];
			else
				b1[i]=b1[i-1];
			
			if(c[n-i]>0)
				c[n-i-1]=a[n-i-1]+c[n-i];
			else
				c[n-i-1]=a[n-i-1];

			if(c[n-i-1]>c1[n-i])
				c1[n-i-1]=c[n-i-1];
			else
				c1[n-i-1]=c1[n-i];
		}
		Max=b1[0]+c1[1];
		for(i=1;i<n-1;i++)
			if(Max<b1[i]+c1[i+1])
				Max=b1[i]+c1[i+1];
		printf("%d\n",Max);
	}
	return 0;
}
