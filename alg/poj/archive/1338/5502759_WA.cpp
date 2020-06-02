#include<iostream>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int i,cnt,n;
	while(scanf("%d",&n),n)
	{
		cnt=1;
		if(n==1)
		{
			i=2;
			goto loop;
		}
		for(i=2;cnt!=n;i++)
			if(i%2==0||i%3==0||i%5==0)
				cnt++;
    loop:printf("%d\n",i-1);
	}
	return 0;
}
