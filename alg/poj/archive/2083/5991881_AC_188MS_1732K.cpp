#include<iostream>
#include<cstring>
using namespace std;

char str[2200][2200];

void f(int n,int i,int j)
{
	if(n==1)
	{
		str[i][j]='X';
		return;
	}
	int t,s=1;
	for(t=1;t<=n-2;t++)
		s*=3;
	f(n-1,i,j);
	f(n-1,i,j+2*s);
	f(n-1,i+s,j+s);
	f(n-1,i+2*s,j);
	f(n-1,i+2*s,j+2*s);
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,i,j,s;
	while(scanf("%d",&n)!=EOF&&n!=-1)
	{
		s=1;
		for(i=1;i<=n-1;i++)
			s*=3;
		for(i=1;i<=s;i++)
			for(j=1;j<=s;j++)
				str[i][j]=' ';
		f(n,1,1);
		for(i=1;i<=s;i++)
		{
			for(j=1;j<=s;j++)
				printf("%c",str[i][j]);
			printf("\n");
		}
		printf("-\n");
	}
	return 0;
}