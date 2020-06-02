#include<iostream>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	char a1[12],a2[12],sum[12];short int i,j,n,m,k,c;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		c=0;
		for(j=0;j<=11;j++)
		{
			sum[j]='0';
		}
		scanf("%s%s",a1,a2);
		for(j=strlen(a1);j<=11;j++)
			a1[j]='0';
		for(j=strlen(a2);j<=11;j++)
			a2[j]='0';
		for(j=0;j<=11;j++)
		{
			sum[j]=char(48+short int(a1[j]+a2[j]-96+c)%10);
			c=short int(a1[j]+a2[j]-96+c)/10;
		}
		for(j=0;j<=11&&sum[j]=='0';j++);
		for(k=11;k>=0&&sum[k]=='0';k--);
		for(m=j;m<=k;m++)
			putchar(sum[m]);
		putchar('\n');
	}
	return 0;
}


		


