#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;
int c;

void change(char* s1,char* s2,char* s12)
{
	int i,j,k;
	for(i=0;i<c;i++)
	{
		s12[2*i]=s2[i];
		s12[2*i+1]=s1[i];
	}
	s12[2*c]='\0';
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,t;
	char s1[105],s2[105],s12[205],t1[105],t2[105],t12[205],temp[205];
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d",&c);
		scanf("%s%s%s",s1,&s2,s12);
		strcpy(t1,s1);
		strcpy(t2,s2);
		for(j=1;;j++)
		{
			change(t1,t2,t12);
			if(j==1)
			{
				strcpy(temp,t12);
			}
			if(strcmp(t12,s12)==0)
			{
				printf("%d %d\n",i,j);
				break;
			}
			if(strcmp(t12,temp)==0&&j!=1)
			{
				printf("%d -1\n",i);
				break;
			}
			for(k=0;k<c;k++)
			{
				t1[k]=t12[k];
				t2[k]=t12[k+c];
			}
			t1[k]='\0';
			t2[k+c]='\0';
		}
	}
	return 0;
}