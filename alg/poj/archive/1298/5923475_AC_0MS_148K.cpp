#include<iostream>
#include<cstring>
using namespace std;

char code[205],str[20];

int main()
{
//	freopen("in.txt","r",stdin);
	int i,n;
	while(true)
	{
		gets(str);
		if(strcmp(str,"ENDOFINPUT")==0)
			break;
		gets(code);
		n=strlen(code);
		for(i=0;i<n;i++)
		{
			if(code[i]<='Z'&&code[i]>='A')
				code[i]=(code[i]-'A'+21)%26+'A';
		}
		puts(code);
		gets(str);
	}
	return 0;
}