#include<iostream>
using namespace std;
#define inf 100000

int f[1002][1002];

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,m,n,x,Max=0;
	scanf("%d%d%d",&n,&m,&x);
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
		{
			if(i==j)
				f[i][j]=0;
			else
			{
				f[i][j]=inf;
				f[j][i]=inf;
			}
		}
	while(m--)
	{
		scanf("%d%d%d",&i,&j,&k);
		f[i][j]=k;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			for(k=1;k<=n;k++)
				if(f[i][j]+f[j][k]<f[i][k])
					f[i][k]=f[i][j]+f[j][k];
	for(i=1;i<=n;i++)
	{
		if(f[i][x]+f[x][i]>Max)
			Max=f[i][x]+f[x][i];
	}
	printf("%d\n",Max);
	return 0;
}