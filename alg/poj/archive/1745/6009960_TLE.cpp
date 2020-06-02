#include<iostream>
using namespace std;

int a[10002];

int n,k;
int sum;

bool dfs(int level)
{
	if(level==n)
	{
		if(sum%k==0)
			return true;
		else 
			return false;
	}
	sum+=a[level+1];
	if(dfs(level+1))
		return true;
	sum-=a[level+1];
	sum-=a[level+1];
	if(dfs(level+1))
		return true;
	sum+=a[level+1];
	return false;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i;
	bool flag=false;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sum=0;
	sum+=a[1];
	if(dfs(1))
		flag=true;
	if(!flag)
	{
		sum=0;
		sum-=a[1];
		if(dfs(1))
			flag=true;
	}
	if(flag)
		printf("Divisible\n");
	else
		printf("Not divisible\n");
	return 0;
}