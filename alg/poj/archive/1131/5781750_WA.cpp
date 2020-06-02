#include<iostream>
using namespace std;

char s[1000];

int main()
{
//	freopen("in.txt","r",stdin);
	double dec;
	int a,i;
	while(scanf("%s",s)!=EOF)
	{
		i=2;dec=0;a=8;
		while(s[i]!='\0')
		{
			dec+=(s[i]-'0')*1.0/a;
			i++;
			a*=8;
		}
		printf("%s [8] = %.350g [10]\n",s,dec);
	}
	return 0;
}

