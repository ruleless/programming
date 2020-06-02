#include <iostream>
#include <cstdio>

using namespace std;

int money[100006],n,m,low,high;

bool check(int mid)
{
	int i,j,k;
	k=0;
	j=0;
	for(i=0;i<n;)
	{
		j+=money[i];
		if(j>mid)
		{
			
			k++;
		//	printf("%d %d\n",k,j-money[i]);
			j=0;
			if(k>=m)
			{
				return false;
			}
		}
		else
		{
			i++;
		}
	}
	return true;
}

void solve()
{
	int i,j,k,mid;
	while(low<high)
	{
		mid=(low+high)/2;
		if(check(mid))
		{
			high=mid;
		}
		else
		{
			low=mid+1;
		}
	}
	printf("%d\n",low);
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k;
	scanf("%d%d",&n,&m);
	high=0;low=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&money[i]);
		if(money[i]>low)
		{
			low=money[i];
		}
		high+=money[i];
	}
	solve();
	return 0;
}