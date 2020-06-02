#include<iostream>
#include<stack>
using namespace std;

int tme[10006];

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,pre,n,temp;
	scanf("%d",&n);
	int res=0;
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
		if(res<tme[i])
			res=tme[i];
	}
	printf("%d\n",res);
	return 0;
}