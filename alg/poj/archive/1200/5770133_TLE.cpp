#pragma warning (disable:4786)
#include<iostream>
#include<map>
#include<string>
using namespace std;

map<string,int>Map;

char s[16000006];
char str[16000006];

void strcpy1(int i,int n)
{
	int j;
	for(j=i;j<i+n;j++)
		str[j-i]=s[j];
	str[j-i]='\0';
}


int main()
{
//	freopen("in.txt","r",stdin);
	int n,nc,i;
	scanf("%d%d%s",&n,&nc,s);
	nc=strlen(s);
	for(i=0;i<=nc-n;i++)
	{
		strcpy1(i,n);
	//	printf("%s\n",str);
		Map[str]++;
	}
	printf("%d\n",Map.size());
	return 0;
}
		