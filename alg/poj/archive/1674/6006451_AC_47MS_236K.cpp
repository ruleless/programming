#include<iostream>
using namespace std;

int a[10005];
int hash[10005];

int main()
{
//	freopen("in.txt","r",stdin);
	int n,i,cnt,temp,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			hash[a[i]]=i;
		}
		cnt=0;
		for(i=1;i<n;i++)
		{
			if(a[i]!=i)
			{
				cnt++;
				temp=a[i];
				a[i]=i;
				a[hash[i]]=temp;
				hash[temp]=hash[i];
				hash[i]=i;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}