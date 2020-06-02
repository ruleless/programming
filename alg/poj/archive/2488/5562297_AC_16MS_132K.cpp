#include <iostream>

using namespace std;

#define N 26

struct state { int x; int y; };
struct statemove { int x; int y; };

bool visited[N][N];
state path[N];
const statemove move[8] = { {-1, -2}, {1, -2}, {-2, -1}, {2, -1},
{-2, 1}, {2, 1}, {-1, 2}, {1, 2} };

int p, q;

bool dfs(int x, int y, int d);

int main()
{
	//freopen("in.txt","r",stdin);
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d%d", &p, &q);
		printf("Scenario #%d:\n", i);
		for(int j=0; j<p; ++j)
    		for(int k=0; k<q; ++k)
         		visited[j][k] = false;
		visited[0][0] = true;
		path[0].x = 0;
		path[0].y = 0;
		if(!dfs(0, 0, 0)) printf("impossible\n\n");
		else
		{
			for(int m=0; m<p*q; ++m)
	     		printf("%c%d", path[m].y+'A', path[m].x+1);
			printf("\n\n");
		}
	}
	return 0;
}

bool dfs(int x, int y, int d)
{
	if(d==p*q-1)
	{
		return true;
	}
	else
	{
		int xx, yy;
		for(int i=0; i<8; ++i)
		{
			xx = x+move[i].x;
			yy = y+move[i].y;
			if(xx>=0 && xx<p && yy>=0 && yy<q
				 && visited[xx][yy]==false)
			{
				visited[xx][yy] = true;
				path[d+1].x = xx;
				path[d+1].y = yy;
				if(dfs(xx, yy, d+1)) return true;
				else visited[xx][yy] = false;
			}
		}
		return false;
	}
}
