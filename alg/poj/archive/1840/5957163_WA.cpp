#include<iostream>
using namespace std;

bool hash[12500009*5]={false};

int main()
{
//	freopen("in.txt","r",stdin);
	int a1,a2,a3,a4,a5;
	int x1,x2,x3,x4,x5,sum=0;
	scanf("%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5);
	for(x1=-50;x1<=50;x1++)
		if(x1!=0)
		{
			for(x2=-50;x2<=50;x2++)
				if(x2!=0)
				{
					hash[a1*x1*x1*x1+a2*x2*x2*x2+6250000*3]=true;
				}
		}
	for(x3=-50;x3<=50;x3++)
		if(x3!=0)
		{
			for(x4=-50;x4<=50;x4++)
				if(x4!=0)
				{
					for(x5=-50;x5<=50;x5++)
						if(x5!=0)
						{
							if(hash[-a3*x3*x3*x3-a4*x4*x4*x4-a5*x5*x5*x5+6250000*3])
								sum++;
						}
				}
		}
	printf("%d\n",sum);

	return 0;
}