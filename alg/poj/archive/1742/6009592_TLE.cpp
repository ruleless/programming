#include<iostream>
using namespace std;

int a[103],c[103],x[103];
int m,n,cnt;
bool hash[100003];


void dfs(int level)
{
	int i,sum=0;
	for(i=1;i<=level;i++)
		sum+=x[i]*a[i];
	if(sum>m)
		return;
	hash[sum]=true;
	if(level==n)
	{
		return;
	}

	for(i=0;i<=c[level+1];i++)
	{
		x[level+1]=i;
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