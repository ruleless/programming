#include<iostream>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	double t,s;int n;
	scanf("%lf",&t);
	while(t!=.00)
	{
		s=0;
		for(n=1;s+1.0/(n+1)<t;n++)
			s+=1.0/(n+1);
		printf("%d  card(s)\n",n);
		scanf("%lf",&t);
	}
	return 0;
}
