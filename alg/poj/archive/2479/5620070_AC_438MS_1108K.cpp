#include<iostream>
using namespace std;

int a[50005],b[50005],b1[50005],c[50005],c1[50005];

int main()
{
//	freopen("in.txt","r",stdin);
	int t,n,i,j,Max;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		for(j=0;j<n;j++)
			scanf("%d",&a[j]);
		b[0]=a[0];
		b1[0]=a[0];
		c[n-1]=a[n-1];
		c1[n-1]=a[n-1];
		for(j=1;j<n;j++)
		{
			if(b[j-1]>0)
				b[j]=a[j]+b[j-1];
			else
				b[j]=a[j];

			if(b[j]>b1[j-1])
				b1[j]=b[j];
			else
				b1[j]=b1[j-1];

			if(c[n-j]>0)
				c[n-j-1]=c[n-j]+a[n-j-1];
			else
				c[n-j-1]=a[n-j-1];

			if(c[n-j-1]>c1[n-j])
				c1[n-j-1]=c[n-j-1];
			else
				c1[n-j-1]=c1[n-j];
		}
		Max=b1[0]+c1[1];
		for(j=1;j<n-1;j++)
			if(b1[j]+c1[j+1]>Max)
				Max=b1[j]+c1[j+1];
		printf("%d\n",Max);
	}
	return 0;
}