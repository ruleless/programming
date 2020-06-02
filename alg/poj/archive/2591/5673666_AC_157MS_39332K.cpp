#include<iostream>
using namespace std;

int a[10000000];

int main()
{
//	freopen("in.txt","r",stdin);
	int two,three,i;
	a[0]=1;
	two=0;three=0;
	for(i=1;i<10000000;i++)
	{
		if(2*a[two]+1<3*a[three]+1)
		{
			a[i]=2*a[two]+1;two++;
		}
		else if(2*a[two]+1>3*a[three]+1)
		{
			a[i]=3*a[three]+1;three++;
		}
		else if(2*a[two]+1==3*a[three]+1)
		{
			a[i]=2*a[two]+1;two++;three++;
		}
	}
	while(scanf("%d",&i)!=EOF)
		printf("%d\n",a[i-1]);
	return 0;
}

