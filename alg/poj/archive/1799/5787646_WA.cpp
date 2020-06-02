#include<iostream>
#include<cmath>
#define pi 3.14159256
using namespace std;

int main()
{
	float R;
	int cse,n,i;
	scanf("%d",&cse);
	for(i=1;i<=cse;i++)
	{
		scanf("%f%d",&R,&n);
		printf("Scenario #%d:\n%.3f\n\n",cse,R*sin(pi/n)/(1+sin(pi/n)));
	}
	return 0;
}
