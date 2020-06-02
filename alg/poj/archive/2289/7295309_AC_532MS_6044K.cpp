#include <iostream>
#include <cstdio>

using namespace std;

bool edge[1550][1050];
int m,n;
int link[1050][1050];
bool vis[1050];

bool Find(int a,int mid)
{
	int i,j,k;
	for(i=1;i<=m;i++)
	{
		if(edge[a][i]&&!vis[i])
		{
			vis[i]=true;
			if(link[i][0]<mid)
			{
				link[i][ ++link[i][0] ]=a;
				return true;
			}
			else
			{
				for(j=1;j<=link[i][0];j++)
				{
					if(Find(link[i][j],mid))
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
	memset(link,0,sizeof(link));
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		if(!Find(i,mid))
		{
			return false;
		}
	}
	return true;
}

int solve()
{
	int i,j,k,low=0,high=n;
	while(low<high)
	{
		int mid=(low+high)/2;
		if(check(mid))
		{
			high=mid;
		}
		else
		{
			low=mid+1;
		}
	}
	return low;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k;
	while(scanf("%d%d",&n,&m)!=EOF&&!(n==0&&m==0))
	{
		memset(edge,0,sizeof(edge));
		for(i=1;i<=n;i++)
		{
			char temp[20];
			scanf("%s",temp);
			while(getchar()!='\n')
			{
				scanf("%d",&j);
				j++;
				edge[i][j]=true;
			}
		}
	//	printf("%d\n",check(2));
		printf("%d\n",solve());
	}
	return 0;
}