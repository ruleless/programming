#include<iostream>

using namespace std;

int main()
{
	int a,b;
	cin>>a>>b;
	while(a<=10&&a>=0&&b<=10&&b>=0)
	{
		cout<<a+b<<endl;
		cin>>a>>b;
	}
	return 0;
}
