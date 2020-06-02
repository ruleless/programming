#include<iostream>
using namespace std;

int a[120];
int num[120][120];

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&num[i][j]);
	memset(a,0,sizeof(a));
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(num[i][j]==3)
				a[i]++;
		}
	}
	i=1;
	for(j=2;j<=n;j++)
	{
		if(a[j]>a[i])
			i=j;
	}
	printf("%d\n",i);
	return 0;
}
