#include<iostream>
#include<cmath>
using namespace std;
#define pi 3.14159

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int N=0,Z;double x,y;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		scanf("%lf%lf",&x,&y);
		Z=ceil((x*x+y*y)*pi*.5/50);
		printf("Property %d: This property will begin eroding in year %d.\n",i,Z);
	}
	printf("END OF OUTPUT.");
	return 0;
}
