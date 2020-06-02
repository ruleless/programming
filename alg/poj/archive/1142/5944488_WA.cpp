#include<iostream>
#include<cmath>
using namespace std;

bool isprime(int n)
{
	int i;
	if(n==0||n==1)
		return false;
	if(n==2)
		return true;
	if(n%2==0)
		return false;
	for(i=3;i<int(sqrt(n*1.0));i+=2)
		if(n%i==0)
			return false;
	return true;
}

int digit_sum(int n)
{
	int sum = 0;
	while ( n > 0 )
	{
		sum += n%10;
		n /= 10;
	}
	return sum;
}

int cut(int n)
{
	if(isprime(n))
		return digit_sum(n);
	for(int i = (int) sqrt(1.0*n); i >= 2; i--) {
		if(!(n%i))
			return cut(i) + cut(n / i);
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int n,i;
	while(scanf("%d",&n)!=EOF&&n)
	{
		for(i=n+1;;i++)
			if( !isprime(i) )
				if(digit_sum(i)==cut(i))
					break;
		printf("%d\n",i);
	}
	return 0;
}