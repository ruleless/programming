#include <stdio.h>
#include <string.h>
#define N 22

int a[N][N];
int used[N][N];

int n,m,x,y;
int num;

int dir[8][2] ={-1,0,-1,1,0,1,1,1,1,0,1,-1,0,-1,-1,-1};

void search(int x, int y)
{
	used[x][y] = 1;
	for (int i=0; i<8; i++)
	{
		int nx = x+dir[i][0];
		int ny = y+dir[i][1];
		if(a[nx][ny] == 0 && i%2==0) num++;
		if (nx>0 && nx<=n && ny>0 && ny<=m)
		{
			if (a[nx][ny] == 1 && used[nx][ny] == 0) search(nx,ny);
		}
	}
}


int main()
{
	while (scanf("%d%d%d%d", &n, &m, &x, &y) != EOF && n)
	{	
		memset(a,0,sizeof(a));
		memset(used,0,sizeof(used));
		for (int i=1; i<=n; i++)
		{
			getchar();
			for (int j=1; j<=m; j++)
			{
				if (getchar() == 'X') a[i][j] = 1;
				else a[i][j] = 0;
			}
		}
		num=0;
		search(x,y);
		printf("%d\n", num);
	}
	return 0;
}
