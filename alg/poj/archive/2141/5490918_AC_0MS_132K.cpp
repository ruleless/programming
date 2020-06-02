#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	char key[26],key1[26];
	char c[81];
	int i;
	scanf("%s",key);
	for(i=0;i<26;i++)
		key1[i]=char(key[i]+'A'-'a');
	getchar();
	gets(c);
	//printf("%s\n",key);
	//printf("%s",c);
	//putchar('\n');
	for(i=0;i<strlen(c);i++)
	{
		if(c[i]<='Z'&&c[i]>='A')
			c[i]=key1[int(c[i]-'A')];
		if(c[i]<='z'&&c[i]>='a')
			c[i]=key[int(c[i]-'a')];
	}
	printf("%s\n",c);
	return 0;
}