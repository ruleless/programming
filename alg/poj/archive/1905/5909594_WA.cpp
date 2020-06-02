#include<iostream>
#include<cmath>
using namespace std;

#define pi 3.14159256

int main()
{
//	freopen("in.txt","r",stdin);
	double l,l1,n,c,mid,temp,a,b,t1,t2;
	while(scanf("%lf%lf%lf",&l,&n,&c)&&!(l==-1&&n==-1&&c==-1))
	{
		l1=(1+n*c)*l;
		temp=l/l1;
		if(temp==1)
		{
			printf( "0.000\n" );
			continue;
		}
		//printf("%lf",l/l1);
		a=0;b=pi;
		while(b-a>1e-7)
		{
			mid=(b+a)/2;
			if(a==0)
				t2=1;
			else
				t2=2*sin(a/2)/a;
			t1=2*sin(mid/2)/mid;
			if( (t1-temp)*(t2-temp)<0 )
			{
				//printf("%lf\n",(a+b)/2);

				b=mid;
			}
			else
			{
				a=mid;
			}
		}
	//	printf("%lf",temp);
	//	printf("%lf\n",4*sin((a+b)/4)/(a+b)-temp);
	//	printf("%lf\n",(a+b)/2);
		printf( "%.3lf\n",2*l1/(a+b)*(1-cos( (a+b)/4 )) );
	}
	return 0;
}