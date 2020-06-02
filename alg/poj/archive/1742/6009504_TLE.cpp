#include<iostream>
using namespace std;

int a[103],c[103],x[103];
int m,n,cnt;
bool hash[100003];

bool check(int k)
{
	int i,sum=0;
	for(i=1;i<=k;i++)
		sum+=x[i]*a[i];
	if(sum<=m)
		return true;
	return false;
}

void dfs(int level)
{
	int i,sum=0;
	if(level==n)
	{
		for(i=1;i<=n;i++)
			sum+=x[i]*a[i];
		hash[sum]=true;
		
		return;
	}

	for(i=0;i<=c[level+1];i++)
	{
		x[level+1]=i;
		if(check(level+1))
			dfs(level+1);
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i;
	while( scanf("%d%d",&n,&m)!=EOF&&!(n==0&&m==0) )
	{
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(i=1;i<=n;i++)
			scanf("%d",&c[i]);
		cnt=0;
		memset(hash,0,sizeof(hash));
		for(i=0;i<=c[1];i++)
		{
			x[1]=i;
			dfs(1);
		}
		for(i=1;i<=m;i++)
			if(hash[i])
				cnt++;
		printf("%d\n",cnt);
	}
	return 0;
}