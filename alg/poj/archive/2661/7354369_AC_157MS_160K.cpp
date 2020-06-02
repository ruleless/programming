#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;
#define eps 10e-11

int main()
{
	int i,j,k,y;
	while(scanf("%d",&y)!=EOF&&y)
	{
		k=(y-1960)/10+2;
		double z=pow(2.,k);
		
		int n=1;
		while(true)
		{
			z-=log(n*1.0)/log(2.);
			if(z<eps)
			{
				break;
			}
			n++;
		}
		n--;
		printf("%d\n",n);
	}
	return 0;
}