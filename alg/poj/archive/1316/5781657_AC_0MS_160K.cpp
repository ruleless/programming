#include<iostream>
using namespace std;

bool a[10006]={false};

int main()
{
	int i;
	for(i=1;i<10000;i++)
	{
		if(i+i/1000+(i%1000)/100+(i%100)/10+i%10<10000)
			a[i+i/1000+(i%1000)/100+(i%100)/10+i%10]=true;
		if(!a[i])
			printf("%d\n",i);
	}
	return 0;
}
