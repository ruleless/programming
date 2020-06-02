#include<iostream>
#include<cstring>
using namespace std;

float f[35][35];
char money[35][20];
int n;

int main()
{
///	freopen("in.txt","r",stdin);
	int i,j,k,m,cse=0;
	float x;
	char c1[20],c2[20];
	while(scanf("%d",&n),n)
	{
		cse++;
		memset(f,0,sizeof(f));
		for(i=1;i<=n;i++)
			scanf("%s",money[i]);
		scanf("%d",&m);
		for(k=1;k<=m;k++)
		{
			scanf("%s%f%s",c1,&x,c2);
			for(i=1;i<=n&&strcmp(money[i],c1)!=0;i++);
			for(j=1;j<=n&&strcmp(money[j],c2)!=0;j++);
			f[i][j]=x;
		}
		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
					if(f[i][k]*f[k][j]>f[i][j])
						f[i][j]=f[i][k]*f[k][j];
		for(i=2;i<=n;i++)
			if(f[1][i]*f[i][1]>1)
			{
				printf("Case %d: Yes\n",cse);
				break;
			}
		if(i==n+1)
			printf("Case %d: No\n",cse);
	}
	return 0;
}