#include<iostream>
#include<cstring>
using namespace std;

char str1[5002],str2[5002];
short int f[5001][5001];
int N;

void nz(char*str)
{
	int n=strlen(str),i;char c;
	for(i=0;i<n/2;i++)
	{
		c=str[n-i-1];
		str[n-i-1]=str[i];
		str[i]=c;
	}
}

void dp()
{
	int m,n,k=strlen(str1);
	for(m=0;m<=k;m++)
		f[m][0]=0;
	for(n=0;n<=k;n++)
		f[0][n]=0;

	for(m=1;m<=k;m++)
		for(n=1;n<=k;n++)
		{
			if(str1[m-1]==str2[n-1])
				f[m][n]=f[m-1][n-1]+1;
			else
				f[m][n]=((f[m-1][n]>f[m][n-1])?f[m-1][n]:f[m][n-1]);
		}
}





int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%d%s",&N,str1);
	strcpy(str2,str1);
	nz(str2);
	int n=strlen(str1);
	dp();
	printf("%d\n",n-f[n][n]);
	//printf("%s\n",str2);
	return 0;
}