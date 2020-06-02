#include<iostream>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int r,e,c,n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&r,&e,&c);
		if(r<e-c)
			printf("advertise\n");
		else if(r==e-c)
			printf("does not matter\n");
		else
			printf("do not advertise\n");
	}
	return 0;
}