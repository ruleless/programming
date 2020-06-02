#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int s,n,i;
	scanf("%d",&s);
	n=ceil( (sqrt( double(8*s+1) )-1)*1.0/2 );
	for(i=n;( i*(i+1)/2-s )%2==1;i++);
	printf("%d\n",i);
	return 0;
}