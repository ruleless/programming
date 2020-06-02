#include<iostream>
using namespace std;

bool f(int n)
{
	int sum=0,s=10000,s1=0,s2=0;
	while(s!=1)
	{
		sum+=(n%s)/(s/10);
		s/=10;
	}
	s=n;
	while(s!=0)
	{
		s1+=s%12;
		s/=12;
	}
	if(sum!=s1)
		return false;
	s=n;
	while(s!=0)
	{
		s2+=s%16;
		s/=16;
	}
	if(sum!=s2)
		return false;
	return true;
}

int main()
{
	int i;
	for(i=2992;i<10000;i++)
		if(f(i))
			printf("%d\n",i);
	return 0;
}