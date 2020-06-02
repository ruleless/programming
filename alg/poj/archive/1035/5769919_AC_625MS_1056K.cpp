#pragma warning (disable:4786)
#include<iostream>
#include<string>
#include<map>
using namespace std;

map<string,int>Map;
map<string,int>::iterator it;

char dic[10003][17];
int cnt;

bool is(char*s1,char*s2)
{
	int i,j,k;
	if(strlen(s1)==strlen(s2))
	{
		i=0;
		k=strlen(s1);
		for(j=0;j<k;j++)
			if(s1[j]!=s2[j])
				i++;
		if(i==1)
			return true;
	}
	else if(strlen(s1)==strlen(s2)+1)
	{
		i=0;j=0;
		k=strlen(s1);
		while(1)
		{
			if(j==k||i==k-1)
				break;
			else if(s2[i]==s1[j])
			{
				i++;
				j++;
			}
			else 
				j++;
		}
		if(i==k-1)
			return true;
	}
	else if(strlen(s1)==strlen(s2)-1)
	{
		i=0;j=0;
		k=strlen(s2);
		while(1)
		{
			if(j==k||i==k-1)
				break;
			else if(s1[i]==s2[j])
			{
				i++;
				j++;
			}
			else 
				j++;
		}
		if(i==k-1)
			return true;
	}
	return false;
}


int main()
{
	int i;
//	freopen("in.txt","r",stdin);
	char str[17];
	cnt=0;
	while(scanf("%s",dic[cnt]),strcmp(dic[cnt],"#")!=0)
	{
		Map[dic[cnt]]=1;
		//printf("%d\n",Map[dic[cnt]]);
		cnt++;
	}
	while(scanf("%s",str),strcmp(str,"#")!=0)
	{
		if(Map[str]==1)
			printf("%s is correct\n",str);
		else
		{
			printf("%s:",str);
			for(i=0;i<cnt;i++)
				if(is(str,dic[i]))
					printf(" %s",dic[i]);
			printf("\n");
		}
	}
	
	return 0;
}
