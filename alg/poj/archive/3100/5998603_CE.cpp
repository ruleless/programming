#include<iostream>
#include<cmath>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int N,B,i,j,k;
	while(scanf("%d%d",&B,&N)!=EOF&& !(B==0&&N==0) )
	{
		for(i=1;int (pow(i,N))<=B;i++);
		if(int( pow(i,N) )==B)
			k=i;
		else
		{
			if(int( pow(i,N) )-B>B-int( pow(i-1,N) ) )
				k=i-1;
			else
				k=i;
		}
		printf("%d\n",k);
	}
	return 0;
}