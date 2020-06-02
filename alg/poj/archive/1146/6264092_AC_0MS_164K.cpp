#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	char c[60];
	while(scanf("%s",c),strcmp(c,"#")!=0)
	{
		if(next_permutation(c,c+strlen(c)))
		{
			printf("%s\n",c);
		}
		else
		{
			printf("No Successor\n");
		}
	}
}