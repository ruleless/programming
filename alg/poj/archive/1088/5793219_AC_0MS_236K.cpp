#include<iostream>
using namespace std;

int R,C,f[101][101],a[101][101];

int dp(int i,int j)
{
	if(f[i][j]>0)
		return f[i][j];
	int Max=0;
	if(i-1>=1&&a[i-1][j]<a[i][j]&&Max<dp(i-1,j))
		Max=f[i-1][j];
	if(i+1<=R&&a[i+1][j]<a[i][j]&&Max<dp(i+1,j))
		Max=f[i+1][j];
	if(j-1>=1&&a[i][j-1]<a[i][j]&&Max<dp(i,j-1))
		Max=f[i][j-1];
	if(j+1<=C&&a[i][j+1]<a[i][j]&&Max<dp(i,j+1))
		Max=f[i][j+1];
	return f[i][j]=Max+1;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j;
	memset(f,0,sizeof(f));
	scanf("%d%d",&R,&C);
	for(i=1;i<=R;i++)
		for(j=1;j<=C;j++)
			scanf("%d",&a[i][j]);
	int Max=0;
	for(i=1;i<=R;i++)
		for(j=1;j<=C;j++)
		{
			dp(i,j);
			if(Max<f[i][j])
				Max=f[i][j];
		}
	printf("%d\n",Max);
	return 0;
}
