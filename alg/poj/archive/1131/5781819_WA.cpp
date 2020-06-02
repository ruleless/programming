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
		if(s[1]=='\0')
		{
			printf("%s [8] = %c [10]\n",s,s[0]);
			continue;
		}
		while(s[i]!='\0')
		{
			dec+=double(s[i]-'0')/double(a);
		//	printf("%c %.35f\n",s[i],dec);
			i++;
			a*=8;
		}
		printf("%s [8] = %.350g [10]\n",s,dec);
	}
	return 0;
}