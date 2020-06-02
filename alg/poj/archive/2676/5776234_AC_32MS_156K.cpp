#include<iostream>
using namespace std;

int a[9][9];
int flag[10];

bool check1(int m,int n)
{
	int i;
	memset(flag,0,sizeof(flag));
	for(i=0;i<9;i++)
	{
		if(a[i][n]!=0)
		{
			flag[a[i][n]]++;
			if(flag[a[i][n]]>1)
				return false;
		}
	}
	memset(flag,0,sizeof(flag));
	for(i=0;i<9;i++)
	{
		if(a[m][i]!=0)
		{
			flag[a[m][i]]++;
			if(flag[a[m][i]]>1)
				return false;
		}
	}
	return true;
}

bool check2(int m,int n)
{
	int i,j;
	memset(flag,0,sizeof(flag));
	for(i=m/3*3;i<m/3*3+3;i++)
		for(j=n/3*3;j<n/3*3+3;j++)
			if(a[i][j]!=0)
			{
				flag[a[i][j]]++;
				if(flag[a[i][j]]>1)
					return false;
			}
	return true;
}

bool dfs(int x)
{
	if(x==-1)
		return true;
	if(a[x/9][x%9]!=0)
		return dfs(x-1);
	int i;
	for(i=1;i<=9;i++)
	{
		a[x/9][x%9]=i;
		if(check1(x/9,x%9)&&check2(x/9,x%9)&&dfs(x-1))
			return true;
		a[x/9][x%9]=0;
	}
	return false;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int t,i,j;
	char s[11];
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<9;i++)
		{
			scanf("%s",s);
			for(j=0;j<9;j++)
				a[i][j]=s[j]-'0';
		}
		dfs(80);
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
				printf("%d",a[i][j]);
			printf("\n");
		}
	}
	return 0;
}



