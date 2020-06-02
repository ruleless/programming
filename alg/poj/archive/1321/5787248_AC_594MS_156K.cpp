#include<iostream>
#include<cstring>
using namespace std;

char a[9][9];
int n,k,cnt;


int x[9];

bool check(int m,int j)
{
	int i;
	for(i=1;i<=m;i++)
		if(x[i]%n==j%n)
			return false;
	return true;
}

void dfs(int m,int i)
{
	if(m==n*n-1)
	{
		if(i==k)
		{
			cnt++;
			return;
		}
		else 
			return;
	}
	if(i==k)
	{
		cnt++;
		return;
	}
	x[i]=m;
	int j;
	for(j=m+1;j<n*n;j++)
	{
		if((x[i]/n!=j/n)&&check(i,j)&&(a[j/n][j%n]=='#'))
			dfs(j,i+1);
	}
}


int main()
{
//	freopen("in.txt","r",stdin);
	int i;
	while(scanf("%d%d",&n,&k)!=EOF&&!(n==-1&&k==-1))
	{
		cnt=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",a[i]);
		//	printf("%s\n",a[i]);
		}
		for(i=0;i<=n*n-k;i++)
			if(a[i/n][i%n]=='#')
				dfs(i,1);
		printf("%d\n",cnt);
	}
	return 0;
}



	