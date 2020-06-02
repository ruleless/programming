#include<iostream>
using namespace std;

int M,N,a[17][301];
int slv[301];

bool dfs(int i)
{
	int j,k;
	int sum=0;
	for(j=0;j<N;j++)
	{
		slv[j]+=a[i][j];
		if(slv[j]>1)
		{
			for(k=0;k<=j;k++)
				slv[k]-=a[i][k];
			return false;
		}
		sum+=slv[j];
	}
	if(sum==N)
		return true;
	for(k=i+1;k<M;k++)
	{
		if(dfs(k))
			return true;
	}
	for(j=0;j<N;j++)
		slv[j]-=a[i][j];
	return false;

}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j;
	bool flag;
	while(scanf("%d%d",&M,&N)!=EOF)
	{
		for(i=0;i<M;i++)
			for(j=0;j<N;j++)
				scanf("%d",&a[i][j]);
		flag=false;		
		for(i=0;i<M;i++)
		{
			memset(slv,0,sizeof(slv));
			if(dfs(i))
			{
				flag=true;
				break;
			}
		}
		if(flag)
			printf("Yes, I found it\n");
		else
			printf("It is impossible\n");
	}
	return 0;
}