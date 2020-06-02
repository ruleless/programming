#include<iostream>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int A,B,C,D;
	while(scanf("%d%d%d%d",&A,&B,&C,&D),!(A==0&&B==0&&C==0&&D==0))
	{
		double x=(1.0*C/A<1.0*D/B)?(1.0*C/A):(1.0*D/B);
		double y=(1.0*C/B<1.0*D/A)?(1.0*C/B):(1.0*D/A);
		double z=100*((x>y)?x:y);
		if(z>100)
			printf("100%%\n");
		else
	    	printf("%d%%\n",int(z));
	}
	return 0;
}
			

