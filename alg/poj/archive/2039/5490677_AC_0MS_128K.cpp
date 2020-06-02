#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,j,k;
	char c[201];
	while(scanf("%d",&n),n)
	{
		scanf("%s",c);
		for(i=0;i<=n-1;i++)
		{
			k=i;
			for(j=1;j<=strlen(c)/n;j++)
			{
				putchar(c[k]);
				if(j%2==0)
					k=k+2*i+1;
				else
					k=k+2*n-2*i-1;
			}
		}
		putchar('\n');

		//printf("%s",c);
		//putchar('\n');
	}
	return 0;
}