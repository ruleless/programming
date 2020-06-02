#include<iostream>
using namespace std;


int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,i;float s;
	while(scanf("%d",&n)!=EOF)
	{
		s=0;
		for(i=2;i<=2*n;i+=2)
			s+=1.0/i;
		printf("Cards  Overhang\n");
		printf("%5d  %8.3f\n",n,s);
	}
	return 0;
}