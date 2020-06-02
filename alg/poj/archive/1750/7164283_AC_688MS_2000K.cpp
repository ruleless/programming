#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

char a[100001][11];
int len[100001],dot[100001],i;
int main()
{
	//printf("NOTE: For reading convenience spaces are replaced with '.' characters. Your output file should contain spaces instead.\n");
    scanf("%s",a[0]);
	len[0]=strlen(a[0]);
	dot[0]=0;
	printf("%s\n",a[0]);
	int k=0;
	i=1;
	while(scanf("%s",a[i])!=EOF)
	{
		len[i]=strlen(a[i]);
		int t=0;
		for(int j=0;j<len[i]&&j<len[i-1];j++)
			if(a[i][j]==a[i-1][j])
				t++;
			else break;
			if(t>dot[i-1])
				dot[i]=dot[i-1]+1;
			else
				dot[i]=t;
			for(int j=0;j<dot[i];j++)
				printf(" ");
			printf("%s\n",a[i]);
			i++;
	}
	return 0;
}

