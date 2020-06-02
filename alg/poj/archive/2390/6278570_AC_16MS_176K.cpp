#include<iostream>
using namespace std;

int main()
{
	int R,M,Y;
	scanf("%d%d%d",&R,&M,&Y);
	double r=R/100.0;
	double s=1;
	while(Y--)
		s*=(1+r);
	printf("%d\n",int(M*s));
	return 0;
}