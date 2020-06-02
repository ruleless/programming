#include<iostream>
#include<cstring>
using namespace std;

char a[10][10],temp[82];
int flag[10];

bool check1(int i,int j)
{
	int k;
	memset(flag,0,sizeof(flag));
	for(k=0;k<9;k++)
		if(a[i][k]!='.')
			flag[a[i][k]-'0']++;
	for(k=1;k<=9;k++)
		if(flag[k]>1)
			return false;
	memset(flag,0,sizeof(flag));
	for(k=0;k<9;k++)
		if(a[k][j]!='.')
			flag[a[k][j]-'0']++;
	for(k=1;k<=9;k++)
		if(flag[k]>1)
			return false;
	return true;
}

bool check2(int i,int j)
{
	int k,l;
	memset(flag,0,sizeof(flag));
	for(k=i/3*3;k<i/3*3+3;k++)
		for(l=j/3*3;l<j/3*3+3;l++)
			if(a[k][l]!='.')
				flag[a[k][l]-'0']++;
	for(k=1;k<=9;k++)
		if(flag[k]>1)
			return false;
	return true;
}

bool dfs(int n)
{
	if(n==-1)
		return true;
	if(a[n/9][n%9]!='.')
		return dfs(n-1);
	char i;
	for(i='1';i<='9';i++)
	{
		a[n/9][n%9]=i;
		if(check1(n/9,n%9)&&check2(n/9,n%9))
			if(dfs(n-1))
				return true;
		a[n/9][n%9]='.';
	}
	return false;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k;
	while(scanf("%s",temp)&&strcmp(temp,"end")!=0)
	{
		k=0;
		for(i=0;i<9;i++)
			for(j=0;j<9;j++)
			{
				a[i][j]=temp[k];
				k++;
			}
		dfs(80);
		for(i=0;i<9;i++)
			printf("%s",a[i]);
		printf("\n");
	}
	return 0;
}
