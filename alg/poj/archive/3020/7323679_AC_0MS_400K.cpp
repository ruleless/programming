#include <iostream>
#include <cstdio>

using namespace std;

int h,w,n;
char str[50][50];
int node[50][50];
bool edge[505][505];
struct Move
{
	int x,y;
};
struct Move move[4]={{-1,0},{0,-1},{1,0},{0,1}};
int link[505];
bool vis[505];

bool Find(int a)
{
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		if(!vis[i]&&edge[a][i])
		{
			vis[i]=true;
			if(link[i]==-1||Find(link[i]))
			{
				link[i]=a;
				return true;
			}
		}
	}
	return false;
}

void solve()
{
	int i,j,k=0;
	memset(link,-1,sizeof(link));
	for(i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		if(Find(i))
		{
			k++;
		}
	}
	printf("%d\n",n-k/2);
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&h,&w);
		for(i=0;i<h;i++)
		{
			scanf("%s",str[i]);
		}
		memset(node,0,sizeof(node));
		n=0;
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				if(str[i][j]=='*')
				{
					node[i][j]=++n;
				}
			}
		}
		memset(edge,0,sizeof(edge));
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				if(node[i][j])
				{
					for(k=0;k<4;k++)
					{
						int x=i+move[k].x;
						int y=j+move[k].y;
						if(x>=0&&x<h&&y>=0&&y<w)
						{
							if(str[x][y]=='*')
							{
								edge[ node[i][j] ][  node[x][y] ]=true;
							}
						}
					}
				}
			}
		}
		solve();
	}
	return 0;
}