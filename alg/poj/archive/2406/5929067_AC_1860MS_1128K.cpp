#include<iostream>
#include<cstring>
using namespace std;

char s[1000005];

bool check(int k)
{
	int i,j;
	int n=strlen(s);
	j=0;
	for(i=k;i<n;i++)
	{
		if(s[i]!=s[j])
			return false;
		j=(j+1)%k;
	}
	return true;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,n;
	while(gets(s),strcmp(s,".")!=0)
	{
		n=strlen(s);
		for(i=1;i<=n;i++)
		{
			if(n%i==0&&check(i))
				break;
		}
		printf("%d\n",n/i);
	}
	return 0;
}