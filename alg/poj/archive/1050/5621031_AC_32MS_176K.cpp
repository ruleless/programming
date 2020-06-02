#include<iostream>
using namespace std;

int a[105][105],b[105],c[105];

int main()
{
//	freopen("in.txt","r",stdin);
	int n,i,j,k,m,l,Max=-100000000;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
		{
			memset(b,0,sizeof(b));
			for(k=i;k<=j;k++)
				for(m=1;m<=n;m++)
					b[m]+=a[k][m];
			c[1]=b[1];
			if(c[1]>Max)
				Max=c[1];
			for(l=2;l<=n;l++)
			{
				if(c[l-1]>0)
					c[l]=c[l-1]+b[l];
				else
					c[l]=b[l];
				if(c[l]>Max)
					Max=c[l];
			}
		}
	printf("%d\n",Max);
	return 0;
}
