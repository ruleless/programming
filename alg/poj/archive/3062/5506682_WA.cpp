#include<iostream>
using namespace std;
int main()
{
	//freopen("in.txt","r",stdin);
	char c[100];char a;
	gets(c);
	printf("%s\n",c);
	while(!feof(stdin))
	{
		gets(c);
		printf("%s\n",c);getchar();
	}
	return 0;
}