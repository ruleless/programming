#include<iostream>
#include<cstring>
using namespace std;

static int lowc[26]=
{36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61};

static int upc[26]=
{10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35};

int main()
{
	//freopen("in.txt","r",stdin);
	char num;
	int n;
	while(scanf("%c",&num)!=EOF)
	{
		getchar();
		/*if(strlen(num)!=1)
		{
			printf("such number is impossible!\n");
			continue;
		}*/
		if(num>='a'&&num<='z')
			n=lowc[num-'a'];
		else if(num>='A'&&num<='Z')
			n=upc[num-'A'];
		else
			n=num-48;
		printf("%d\n",n+1);
	}
	return 0;
}