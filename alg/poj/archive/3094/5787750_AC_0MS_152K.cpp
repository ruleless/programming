#include<iostream>
#include<cstring>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	char num[260];
	int i,sum;
	while(gets(num)&&strcmp(num,"#")!=0)
	{
		sum=0;
		for(i=0;num[i]!='\0';i++)
			if(num[i]!=' ')
				sum+=(i+1)*(num[i]-'A'+1);
		printf("%d\n",sum);
	}
	return 0;
}
