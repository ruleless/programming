#include<iostream>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	char s[36];
	int n,i,k,sum;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",s);
		k=128;sum=0;
		for(i=0;i<8;i++)
		{
			sum+=int(s[i]-48)*k;
			k/=2;
		}
		printf("%d.",sum);

		k=128;sum=0;
		for(i=8;i<16;i++)
		{
			sum+=int(s[i]-48)*k;
			k/=2;
		}
		printf("%d.",sum);

		k=128;sum=0;
		for(i=16;i<24;i++)
		{
			sum+=int(s[i]-48)*k;
			k/=2;
		}
		printf("%d.",sum);

		k=128;sum=0;
		for(i=24;i<32;i++)
		{
			sum+=int(s[i]-48)*k;
			k/=2;
		}
		printf("%d\n",sum);
	}
	return 0;
}