#include<iostream>
#include<cstring>
using namespace std;

void ff(char*a,char*find,char*replace)
{
	int i;
	char b[256],q[256],*p;
	p=strstr(a,find);
	while(p!=NULL)
	{
	strcpy(b,a);
	for(i=strlen(find);i<strlen(p);i++)
		q[i-strlen(find)]=p[i];
	q[i-strlen(find)]='\0';
	strcpy(p,replace);
	strcat(a,q);
	p=strstr(a,find);
	}
}


int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	char find[10][81],replace[10][81],a[256];
	while(scanf("%d",&n),n)
	{
		getchar();
		for(i=0;i<n;i++)
		{
			gets(find[i]);
		    gets(replace[i]);		
		}
		gets(a);	
	    for(i=0;i<n;i++)
		{
		     ff(a,find[i],replace[i]);
				
		}
		printf("%s\n",a);				
	}
	return 0;
}