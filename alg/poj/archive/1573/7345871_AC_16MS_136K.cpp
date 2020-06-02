#include <iostream>
#include <cstdio>

using namespace std;

char map[15][15];
int m,n,s;
int loop,step;
bool vis[15][15];

void solve()
{
	int i,j,k=-1,l=-1;
	i=0;j=s-1;
	memset(vis,0,sizeof(vis));
	loop=step=0;
	while(i!=-1&&j!=-1&&i!=m&&j!=n&&!vis[i][j])
	{
		vis[i][j]=true;
		if(map[i][j]=='S')
		{
			i++;
		}
		else if(map[i][j]=='N')
		{
			i--;
		}
		else if(map[i][j]=='W')
		{
			j--;
		}
		else
		{
			j++;
		}
		step++;
		if(vis[i][j])
		{
			k=i;l=j;
		}
	}
	if(k==-1&&l==-1)
	{
		printf("%d step(s) to exit\n",step);
	}
	else
	{
		i=0;j=s-1;
		memset(vis,0,sizeof(vis));
		vis[k][l]=true;
		while(!vis[i][j])
		{
			if(map[i][j]=='S')
			{
				i++;
			}
			else if(map[i][j]=='N')
			{
				i--;
			}
			else if(map[i][j]=='W')
			{
				j--;
			}
			else
			{
				j++;
			}
			loop++;
		}
		printf("%d step(s) before a loop of %d step(s)\n",loop,step-loop);
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k;
	while(scanf("%d%d%d",&m,&n,&s),m+n+s)
	{
		for(i=0;i<m;i++)
		{
			scanf("%s",map[i]);
		}
		solve();
	}
	return 0;
}