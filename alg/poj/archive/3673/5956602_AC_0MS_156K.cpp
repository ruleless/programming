#include<iostream>
#include<cstring>
using namespace std;

char a[30],b[30];

int main()
{
	scanf("%s%s",a,b);
	int n=strlen(a);
	int m=strlen(b);
	int i,j,sum=0;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			sum+=(a[i]-48)*(b[j]-48);
		}
	printf("%d\n",sum);
	return 0;
}