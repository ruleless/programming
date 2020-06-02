#include <iostream>
#include <cstdio>

using namespace std;

bool mat[55][55];
int cnt,flag[55][55];

struct Move
{
	int x,y;
};
struct Move move[4]={{-1,0},{0,-1},{1,0},{0,1}};
bool edge[1025][1025];

int pre[1025];
bool vis[1025];

int Find(int a)
{
	int i,j,k;
	for(i=1;i<=cnt;i++)
	{
		if(edge[a][i]&&!vis[i])
		{
			vis[i]=true;
			if(pre[i]==-1||Find(pre[i]))
			{
				pre[i]=a;
				return true;
			}
		}
	}
	return false;
}

int solve()
{
	int i,j,k=0;
	memset(pre,-1,sizeof(pre));
	for(i=1;i<=cnt;i++)
	{
		memset(vis,0,sizeof(vis));
		if(Find(i))
		{
			k++;
		}
	}
	return k;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,n,m;
	scanf("%d%d%d",&m,&n,&k);
	memset(mat,0,sizeof(mat));
	while(k--)
	{
		scanf("%d%d",&i,&j);
		mat[j][i]=true;
	}
	cnt=0;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(!mat[i][j])
			{
				flag[i][j]=++cnt;
			}
		}
	}
	memset(edge,0,sizeof(edge));
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(!mat[i][j])
			{
				for(k=0;k<4;k++)
				{
					int x=i+move[k].x;
					int y=j+move[k].y;
					if(x>0&&x<=m&&y>0&&y<=n)
					{
						if(!mat[x][y])
						{
							edge[ flag[i][j] ][ flag[x][y] ]=true;
						}
					}
				}
			}
		}
	}
	if(solve()==cnt)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return true;
}