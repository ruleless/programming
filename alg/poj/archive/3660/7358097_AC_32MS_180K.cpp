#include <iostream>
#include <cstdio>

using namespace std;

int f[105][105],n;

void floyd()
{
	int i,j,k;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(f[i][k]==1&&f[k][j]==1)
				{
					f[i][j]=1;
					f[j][i]=-1;
				}
				if(f[i][k]==-1&&f[k][j]==-1)
				{
					f[i][j]=-1;
					f[j][i]=1;
				}
			}
		}
	}
}

bool check(int k)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		if(i!=k&&f[k][i]==0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k=0,m;
	scanf("%d%d",&n,&m);
	memset(f,0,sizeof(f));
	while(m--)
	{
		scanf("%d%d",&i,&j);
		f[i][j]=1;
		f[j][i]=-1;
	}
	floyd();
	for(i=1;i<=n;i++)
	{
		if(check(i))
		{
			k++;
		}
	}
	printf("%d\n",k);
	return 0;
}