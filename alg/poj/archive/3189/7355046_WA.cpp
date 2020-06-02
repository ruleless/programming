#include <iostream>
#include <cstdio>

using namespace std;

int edge[1005][22],n,b,cap[22];
int link[22][1005],low,high;
bool vis[22];

bool Find(int a)
{
	int i,j,k;
	for(i=1;i<=b;i++)
	{
		if(edge[a][i]>=low&&edge[a][i]<=high&&!vis[i])
		{
			vis[i]=true;
			if(link[i][0]<cap[i])
			{
				link[i][++link[i][0]]=a;
				return true;
			}
			else
			{
				for(j=1;j<=link[i][0];j++)
				{
					if(Find(link[i][j]) )
					{
						link[i][j]=a;
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool check(int mid)
{
	int i,j,k;
	low=1;high=low+mid;
	while(true)
	{
	//	printf("%d %d\n",low,high);
		memset(link,0,sizeof(link));
		k=0;
		for(i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			if(Find(i))
			{
				k++;
			}
		}
		if(k==n)
		{
			return true;
		}
		low+=mid;
		high+=mid;
		if(high>b||mid==0)
		{
			break;
		}
	}
	return false;
}

void solve()
{
	int i,j,k,left,right,mid;
	left=0;right=b-1;
	while(left<right)
	{
		mid=(left+right)/2;
		if(check(mid))
		{
			right=mid;
		}
		else
		{
			left=mid+1;
		}
	}
	printf("%d\n",left+1);
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k;
	scanf("%d%d",&n,&b);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=b;j++)
		{
			scanf("%d",&k);
			edge[i][k]=j;
		}
	}
	for(i=1;i<=b;i++)
	{
		scanf("%d",&cap[i]);
	}
	solve();
	return 0;
}