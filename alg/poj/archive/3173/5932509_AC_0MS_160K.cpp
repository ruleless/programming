#include<iostream>
using namespace std;

int num[22][22];

int main()
{
	int N,S,i,j,a;
	scanf("%d%d",&N,&S);a=S;
	for(j=1;j<=N;j++)
	{
		for(i=1;i<=j;i++)
		{
			num[i][j]=a;
			a=a%9+1;
		}
	}
	for(i=1;i<=N;i++)
	{
		for(a=1;a<i;a++)
			printf("  ");
		for(j=i;j<N;j++)
		{
			printf("%d ",num[i][j]);
		}
		printf("%d\n",num[i][j]);
	}
	return 0;
}