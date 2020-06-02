#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int f[205][205],n;
char map[205][205][29];
char str[29];

bool contain(char* str,int c)
{
	int i,len=strlen(str);
	for(i=0;i<n;i++)
	{
		if(str[i]==c+'a')
		{
			return true;
		}
	}
	return false;
}

void floyd()
{
	int i,j,k,l;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(f[i][k]==1&&f[k][j]==1)
				{
					f[i][j]=1;
					int len=strlen(map[i][j]);
					for(l=0;l<26;l++)
					{
						if(contain(map[i][k],l)&&contain(map[k][j],l))
						{
							map[i][j][len++]=l+'a';
						}
					}
					map[i][j][len]='\0';
				}
			}
		}
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k;
	while(scanf("%d",&n)!=EOF&&n)
	{
		memset(f,0,sizeof(f));
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				map[i][j][0]='\0';
			}
		}
		while(scanf("%d%d",&i,&j),i+j)
		{
			f[i][j]=1;
			scanf("%s",str);
			strcpy(map[i][j],str);
		}	
		floyd();
		while(scanf("%d%d",&i,&j),i+j)
		{
			if(strlen(map[i][j])==0)
			{
				printf("-\n");
			}
			else
			{
				for(k=0;k<26;k++)
				{
					if(contain(map[i][j],k) )
					{
						printf("%c",k+'a');
					}
				}
				printf("\n");
			}
		}
		printf("\n");
	}
	return 0;
}