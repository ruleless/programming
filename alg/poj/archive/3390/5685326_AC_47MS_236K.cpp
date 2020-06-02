#include<iostream>
using namespace std;

int a[10010],f[10010];

int main()
{
//	freopen("in.txt","r",stdin);
	int m,n,i,j,t,sum;
	for(scanf("%d",&t);t>0;t--)
	{
		scanf("%d%d",&m,&n);
		f[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum=a[i];
			f[i]=100000000;
			for(j=i-1;j>=0&&sum<=m;j--)
			{
				if((f[j]+(m-sum)*(m-sum))<f[i])
					f[i]=f[j]+(m-sum)*(m-sum);
				sum+=a[j]+1;
			}
		}
		printf("%d\n",f[n]);
	}
	return 0;
}


