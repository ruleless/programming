#include<iostream>
#include<cmath>
#define pi 3.14159256
using namespace std;

int main()
{
	double s,r,h,v;
	while(scanf("%lf",&s)!=EOF)
	{
		r=sqrt(s/(4*pi));
		v=sqrt(pi*s*(-2*r*r*r*r+s*r*r/pi)/9);
		h=sqrt(s*s/(pi*pi*r*r)-2*s/pi);
		printf("%.2lf\n%.2lf\n%.2lf\n",v,h,r);
	}
	return 0;
}