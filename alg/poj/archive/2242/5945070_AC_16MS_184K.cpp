#include<iostream>
#include<cmath>
using namespace std;
#define pi 3.141592653589793

double f(double a,double b,double c)
{
	double q=(a+b+c)/2.0;
	double s=sqrt( (q-a)*(q-b)*(q-c)*q );
	return a*b*c*pi*0.5/s;
}

int main()
{
//	freopen("in.txt","r",stdin);
	double x1,y1,x2,y2,x3,y3,a,b,c;
	while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)!=EOF)
	{
		a=sqrt( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) );
		b=sqrt( (x1-x3)*(x1-x3)+(y1-y3)*(y1-y3) );
		c=sqrt( (x3-x2)*(x3-x2)+(y3-y2)*(y3-y2) );
		printf("%.2lf\n",f(a,b,c));
	}
	return 0;
}