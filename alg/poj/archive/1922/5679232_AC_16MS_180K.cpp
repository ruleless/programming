#include<iostream>
#include<limits>
#include<cmath>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int n,a,i,b;
	double Min;
	while(scanf("%d",&n),n)
	{
		Min=numeric_limits<double>::max();
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&a,&b);
			if(b>=0&&(4.5*3600/(1.0*a)+1.0*b<Min))
				Min=4.5*3600/a+b;
		}
		printf("%d\n",int(ceil(Min)));
	}
	return 0;
}