#include<iostream>
using namespace std;

int a[102];

int main()
{
//	freopen("in.txt","r",stdin);
	int n,Max,i,j=0,res;
	while(scanf("%d",&n),n)
	{
		j++;
		Max=0;res=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			Max+=a[i];
		}
		for(i=0;i<n;i++)
			if(a[i]>Max/n)
				res+=a[i]-Max/n;
		printf("Set #%d\nThe minimum number of moves is %d.\n\n",j,res);
	}
	return 0;
}