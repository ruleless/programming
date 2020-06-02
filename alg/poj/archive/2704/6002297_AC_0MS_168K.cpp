#include<iostream>
#include<cstring>
using namespace std;

__int64 m[36][36];
char a[36][36];
int n;

void dp()
{
	m[0][0]=1;
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(i!=n-1||j!=n-1)
			{
				if(int(a[i][j]-48)+i<n)
					m[int(a[i][j]-48)+i][j]+=m[i][j];
				if(int(a[i][j]-48)+j<n)
					m[i][int(a[i][j]-48)+j]+=m[i][j];
			}
		}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i;
	while(scanf("%d",&n)!=EOF&&n!=-1)
	{
		memset(m,0,sizeof(m));		
		for(i=0;i<n;i++)
			scanf("%s",a[i]);
		dp();
	/*	for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				printf("%I64d ",m[i][j]);
			printf("\n");
		}*/
		printf("%I64d\n",m[n-1][n-1]);
	}
	return 0;
}