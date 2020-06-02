#include<iostream>
using namespace std;

int N,a[101][101],flag[101];

bool check1(int i,int j)
{
	int l;
	memset(flag,0,sizeof(flag));
	for(l=0;l<N*N;l++)
		flag[a[l][j]]++;
	for(l=1;l<=N*N;l++)
		if(flag[l]!=0&&flag[l]>1)
			return false;
	memset(flag,0,sizeof(flag));
	for(l=0;l<N*N;l++)
		flag[a[i][l]]++;
	for(l=1;l<=N*N;l++)
		if(flag[l]!=0&&flag[l]>1)
			return false;
	return true;
}

bool check2(int i,int j)
{
	memset(flag,0,sizeof(flag));
	int k,l;
	for(k=i/N*N;k<i/N*N+N;k++)
		for(l=j/N*N;l<j/N*N+N;l++)
			flag[a[k][l]]++;
	for(k=1;k<=N*N;k++)
		if(flag[k]!=0&&flag[k]>1)
			return false;
	return true;
}

bool dfs()
{
	int i,j;
	for(i=0;i<N*N;i++)
		for(j=0;j<N*N;j++)
			if(!check1(i,j)||!check2(i,j))
				return false;
	return true;
}

int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%d",&N);
	int i,j;
	for(i=0;i<N*N;i++)
	{
		for(j=0;j<N*N;j++)
		{
			scanf("%d",&a[i][j]);
		//	printf("%d ",a[i][j]);
		}
		//printf("\n");
	}
	if(dfs())
		printf("CORRECT\n");
	else
		printf("INCORRECT\n");
	return 0;
}

