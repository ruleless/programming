#include<iostream>
#define pi 3.1415927
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	float d,t;
	int r,cse=0;
	while(scanf("%f%d%f",&d,&r,&t)&&r!=0)
	{
		cse++;
		printf("Trip #%d: %.2f %.2f\n",cse,pi*d*r/(12*5280),(pi*d*r/(12*5280))*3600/t);
	}
	return 0;
}