#include<iostream>
#include<cmath>
using namespace std;
#define pi 3.14159256

int main()
{
//	freopen("in.txt","r",stdin);
	double D,V,a,b,mid;
	while(scanf("%lf%lf",&D,&V)!=EOF&&!(D==0&&V==0))
	{
		a=0;b=D;
		while(b-a>1e-13)
		{
			mid=(a+b)/2;
			if(D*D*D-6*V/pi-mid*mid*mid==0)
				break;
			else if( (D*D*D-6*V/pi-mid*mid*mid)*(D*D*D-6*V/pi-a*a*a)<0 )
				b=mid;
			else 
				a=mid;
		}
		printf("%.3lf\n",mid);
	}
	return 0;
}