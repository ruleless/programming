#include<iostream>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int n,s,t,sum,t1;
	while(scanf("%d",&n),n!=-1)
	{
		sum=0;
		t1=0;
		while(n--)
		{
			scanf("%d%d",&s,&t);
			sum+=s*(t-t1);
			t1=t;
		}
		printf("%d miles\n",sum);
	}
	return 0;
}
