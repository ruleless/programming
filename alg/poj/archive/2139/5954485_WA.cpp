#include<iostream>
using namespace std;

int f[302][302];
int num[302];

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,n,m,sum=999999,s;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			if(i==j)
				f[i][j]=0;
			else
			{
				f[i][j]=2;
				f[j][i]=2;
			}
		}
	while(m--)
	{
		scanf("%d",&k);
		for(i=1;i<=k;i++)
			scanf("%d",&num[i]);
		for(i=1;i<k;i++)
			for(j=i+1;j<=k;j++)
			{
				f[num[i]][num[j]]=1;
				f[num[j]][num[i]]=1;
			}
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			for(k=1;k<=n;k++)
				if(f[i][j]+f[j][k]<f[i][k])
					f[i][k]=f[i][j]+f[j][k];
	for(i=1;i<=n;i++)
	{
		s=0;
		for(j=1;j<=n;j++)
			s+=f[i][j];
		if(s<sum)
			sum=s;
	}
	printf("%d\n",int(100.0*sum/(n-1)));
	return 0;
}