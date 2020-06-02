#include<iostream>
#include<cstring>
using namespace std;

int strcmp1(char*p,char*q)
{
	int i,j,n=strlen(p),*flag=new int[n];
	for(i=0;i<n;i++)
		flag[i]=0;
	if(strlen(p)!=strlen(q))
		return 0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(p[i]==q[j]&&flag[j]==0)
			{
				flag[j]=1;
			}
	for(i=0;i<n&&flag[i]==1;i++);
	delete []flag;
	if(i==n)
		return 1;
	return 0;
}


int main()
{
	//freopen("in.txt","r",stdin);
	char a1[101],a2[101],temp[101];
	int i,j;
	scanf("%s",a1);
	scanf("%s",a2);
	//printf("%s\n",a1);
	//printf("%s",a2);
	for(i=1;i<=25;i++)
	{
		for(j=0;j<strlen(a2);j++)
		{
			temp[j]='A'+(a2[j]+i-'A')%26;
		}
		temp[j]='\0';
		if(strcmp1(temp,a1)==1)
		{
			printf("YES\n");break;
		}
	}
	if(i==26)
		printf("NO\n");
	//printf("%d",strcmp1("IVOTCIRSUO","VICTORIOUS"));
	//printf("%c",'A'+('Z'+'Y'-'A'-'A')%26);
	return 0;
}
