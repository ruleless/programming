#include<iostream>
using namespace std;

int a[10005];

int main()
{
//	freopen("in.txt","r",stdin);
	int t,i,j,n,temp,cnt;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		cnt=0;
		for(i=1;i<n;i++)
		{
			if(a[i]!=i)
			{
				cnt++;
				for(j=i+1;j<=n&&a[j]!=i;j++);
				temp=a[i];
				a[i]=i;
				a[j]=temp;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}