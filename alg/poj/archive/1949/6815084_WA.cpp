#include<iostream>
#include<stack>
using namespace std;

int tme[10006];

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,pre,n,temp;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&temp,&j);
		int tt=0;
		while(j--)
		{
			scanf("%d",&pre);
			if(tt<tme[pre])
				tt=tme[pre];
		}
		tme[i]=tt+temp;
	}
	printf("%d\n",tme[n]);
	return 0;
}