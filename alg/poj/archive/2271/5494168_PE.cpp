#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int col=0;
	char c[81];
	while(scanf("%s",c)!=EOF)
	{
		if(strcmp(c,"<br>")==0)
		{
			putchar('\n');
			col=0;
		}
		else if(strcmp(c,"<hr>")==0)
		{
			if(col==0)
			{
				printf("--------------------------------------------------------------------------------");
				printf("\n");col=0;
			}
			else
			{
				putchar('\n');
				printf("--------------------------------------------------------------------------------");
				putchar('\n');col=0;
			}
		}
		else if(col+strlen(c)>80)
		{
			printf("\n%s",c);col=strlen(c)+1;
		}
		else if(col+strlen(c)==80)
		{
			printf("%s",c);col=0;
			putchar('\n');
		}
		else if(col+strlen(c)<80)
		{
			printf("%s ",c);col+=strlen(c)+1;
		}
		//printf("%s",c);
	}
	return 0;
}