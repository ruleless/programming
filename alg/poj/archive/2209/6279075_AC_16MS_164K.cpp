#include<iostream>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int n,m,a[150],i,j,t;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		a[i]=1;
		for(j=1;j<=m;j++)
			a[i]*=t;
	}
	t=0;
	for(i=0;i<n;i++)
		if(a[i]>0)
			t+=a[i];
	printf("%d\n",t);
	return 0;
}