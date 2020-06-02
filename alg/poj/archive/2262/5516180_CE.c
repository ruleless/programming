#include<iostream>
#include<cmath>
using namespace std;

bool isp(int num)
{
     if (num <= 2)
     {
         return num == 2;
     }
     
     if (num % 2 == 0)
     {
         return false;
     }
     int iSqrt = (int)sqrt((double)num);

     for (int i = 3; i <= iSqrt; i+=2)
     {
         if (num % i == 0)
         {
             return false;
         }
     }
     return true;
}


int main()
{
	int n,i;
	while(scanf("%d",&n),n)
	{
		for(i=3;i<n;i+=2)
			if(isp(i)&&isp(n-i))
			{
				printf("%d = %d + %d\n",n,i,n-i);
				break;
			}
	}
	return 0;
}
