#include<iostream>
using namespace std;

int num[400][800],m[400][800];


int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		j=n-i+1;
		for(k=1;k<=i;k++)
		{
			scanf("%d",&num[i][j]);
			j+=2;
		}
	}
	j=1;
	for(k=1;k<=n;k++)
	{
		m[n][j]=num[n][j];
		j+=2;
	}
	for(i=n-1;i>=1;i--)
	{
		j=n-i+1;
		for(k=1;k<=i;k++)
		{
			m[i][j]=num[i][j]+((m[i+1][j-1]>m[i+1][j+1])?m[i+1][j-1]:m[i+1][j+1]);
			j+=2;
		}
	}
	printf("%d\n",m[1][n]);
	return 0;
}

