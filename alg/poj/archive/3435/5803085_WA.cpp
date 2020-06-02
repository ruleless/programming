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



bool dfs(int n)
{
	if(n==-1)
		return true;
	if(a[n/(N*N)][n%(N*N)]!=0)
		return dfs(n-1);
	int i;
	for(i=1;i<=(N*N);i++)
	{
		a[n/(N*N)][n%(N*N)]=i;
		if(check1(n/(N*N),n%(N*N))&&check2(n/(N*N),n%(N*N)))
			if(dfs(n-1))
				return true;
		a[n/(N*N)][n%(N*N)]=0;
	}
	return false;
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
	if(dfs(N*N-1))
		printf("CORRECT\n");
	else
		printf("INCORRECT\n");
	return 0;
}

