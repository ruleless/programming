#include<iostream>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int i;double sum=0,s=0;
	for(i=1;i<=12;i++)
	{
		scanf("%lf",&s);
		sum+=s;
	}
	printf("$%.2lf",sum*1.0/12);
	return 0;
}
