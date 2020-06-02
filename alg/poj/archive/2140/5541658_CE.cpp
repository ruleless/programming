#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int j,k=0,n;
	scanf("%d",&n);
	for(j=1;j<=(int)(sqrt(1+8*n)-1)/2;j++)
		if((2*n-j*j+j)%(2*j)==0)
			k++;
	printf("%d\n",k);
	return 0;
}