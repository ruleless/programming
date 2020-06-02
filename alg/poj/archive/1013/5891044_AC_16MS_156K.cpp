#include<iostream>
#include<cstring>
using namespace std;

char s1[3][7],s2[3][7],p[3][6];

bool contain(char c,char* s)
{
	int i;
	int n=strlen(s);
	for(i=0;i<n;i++)
	{
		if(c==s[i])
			return true;
	}
	return false;
}

bool f(char c,int s)
{
	int i;
	for(i=0;i<3;i++)
	{
		if(s==0)
		{
			if(contain(c,s1[i]))
			{
				if(strcmp(p[i],"down")!=0)
					return false;
			}
			else if(contain(c,s2[i]))
			{
				if(strcmp(p[i],"up")!=0)
					return false;
			}
			else
			{
				if(strcmp(p[i],"even")!=0)
					return false;
			}
		}
		else
		{
			if(contain(c,s1[i]))
			{
				if(strcmp(p[i],"up")!=0)
					return false;
			}
			else if(contain(c,s2[i]))
			{
				if(strcmp(p[i],"down")!=0)
					return false;
			}
			else
			{
				if(strcmp(p[i],"even")!=0)
					return false;
			}
		}
	}
	return true;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int t,i,s;
	char c;
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<3;i++)
		{
			scanf("%s%s%s",s1[i],s2[i],p[i]);
		//	printf("%s%s%s\n",s1[i],s2[i],p[i]);
		}
		for(i=0;i<12;i++)
		{
			s=0;
			c=char('A'+i);
			if(f(c,s))
				break;
			s=1;
			if(f(c,s))
				break;

		}
		if(s==0)
			printf("%c is the counterfeit coin and it is light.\n",c);
		else
			printf("%c is the counterfeit coin and it is heavy.\n",c);
	}
	return 0;
}