#include<iostream>
using namespace std;

int main()
{
	int i,n;
	printf("n e\n- -----------\n");
	double res=1;
	printf("0 %g\n",res);
	n=1;
	for(i=1;i<10;i++)
	{
		n*=i;
		res+=1.0/n;
		printf("%d %.9lf\n",i,res);
		
	}
	return 0;
}