#include<iostream>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int f0,f1,f2;
	int A,B,C;
	while(scanf("%d%d%d",&f0,&f1,&f2)!=EOF)
	{
		A=(f0-2*f1+f2)/2;
		B=(-3*f0+4*f1-f2)/2;
		C=f0;
		printf("%d %d %d\n",9*A+3*B+C,16*A+4*B+C,25*A+5*B+C);
	}
	return 0;
}