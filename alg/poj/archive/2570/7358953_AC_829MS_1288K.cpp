#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

bool map[205][205][28];
int n;
char str[29];

void floyd()
{
	int i,j,k,l;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				for(l=0;l<26;l++)
				{
					if(map[i][k][l]&&map[k][j][l])
					{
						map[i][j][l]=true;
					}
				}
			}
		}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	int i,j,k;
	while(scanf("%d",&n)!=EOF&&n)
	{
		memset(map,0,sizeof(map));
		while(scanf("%d%d",&i,&j),i+j)
		{
			scanf("%s",str);
			int len=strlen(str);
			for(k=0;k<len;k++)
			{
				map[i][j][str[k]-'a']=true;
			}
		}
		floyd();
		while(scanf("%d%d",&i,&j),i+j)
		{
			bool flag=true;
			for(k=0;k<26;k++)
			{
				if(map[i][j][k])
				{
					flag=false;
					printf("%c",k+'a');
				}
			}
			if(flag)
			{
				printf("-");
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}