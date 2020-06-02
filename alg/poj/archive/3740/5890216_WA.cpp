#include<iostream>
using namespace std;

int M,N,a[16][300];
int slv[300];

bool dfs(int i)
{
	int j,k;
	if(i==M)
		return false;
	int sum=0;
	for(j=0;j<N;j++)
	{
		slv[j]+=a[i][j];
		if(slv[j]>1)
			return false;
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