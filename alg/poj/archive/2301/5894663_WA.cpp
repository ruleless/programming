#include<iostream>
using namespace std;

int main()
{
	int n,a,b;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&a,&b);
		if(a<b)
			printf("impossible\n");
		else
			printf("%g %g\n",(a+b)*1.0/2,(a-b)*1.0/2);
	}
	return 0;
}
