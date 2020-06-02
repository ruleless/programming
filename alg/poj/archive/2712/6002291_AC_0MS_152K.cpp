#include<iostream>
#include<cstring>
#include <ctype.h>
using namespace std;

char str[140];

bool check(char *s)
{
	int n=strlen(s);
	int i;
	if(n==1)
		if(s[0]!='a'&&s[0]!='A'&&s[0]!='I')
			return false;

	for(i=0;i<n-1;i++)
	{
		if(i==n-2)
		{
			if(s[i]==' ')
				if(s[i+1]!='a'&&s[i+1]!='A'&&s[i+1]!='I')
					return false;
		}
		else if(i==0)  
		{
			if(s[i+1]==' ')
				if(s[i]!='a'&&s[i]!='A'&&s[i]!='I')
					return false;
         }
		else if(s[i-1]==' '&&s[i+1]==' ') 
		{
			if(s[i]!='a'&&s[i]!='A'&&s[i]!='I')
			{
			//	printf("%d\n",i);
				return false;
			}
        }
		if((s[i]>='A'&&s[i]<='Z')&&(s[i+1]>='A'&&s[i+1]<='Z'))
		{
	//		printf("a%d\n",i);
			return false;
		}
		if( isdigit(s[i]) && isalpha(s[i+1]) || isalpha(s[i]) && isdigit(s[i+1]))
		{
		//	printf("b%d\n",i);
			return false;
		}
		if( (!isdigit(s[i])  && !isalpha(s[i]) && s[i] != ' ') && (!isdigit(s[i+1])  && !isalpha(s[i+1]) && s[i+1] != ' ') )
		{
			if(s[i]=='\"'&&s[i+1]=='\"')
				return false;
			if(s[i]!='\"'&&s[i+1]!='\"')
			{
		//		printf("c%d\n",i);
				return false;
			}
		}
	}
	return true;
}

int main()
{
//	freopen("in.txt","r",stdin);
	bool flag;
	while(gets(str),strcmp(str,"#")!=0)
	{
		flag=false;
		if(!check(str))
		{
			flag=true;
		}
		if(flag==true)
			printf("suspicious\n");
		else
		{
			printf("OK\n");
		}
	}
//	getch();
	return 0;
	
}