#include<iostream>
using namespace std;
int main()
{
	char c[100];char a;
	gets(c);
	printf("%s\n",c);
	while(a=getchar()!=EOF)
	{
		gets(c);
		printf("%s\n",c);
	}
	return 0;
}