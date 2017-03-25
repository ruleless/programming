#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100
#define M 100
static int GRID[N][M], n, m;
static int visited[N][M];

int dfs(int a, int b) {
	static int nexti[] = {-1, -1, -1, 0, 0, 1, 1, 1,};
	static int nextj[] = {-1, 0, 1, -1, 1, -1, 0, 1,};
	int res = 1, i, j, k;
	visited[a][b] = 1;
	for (k = 0; k < sizeof(nexti)/sizeof(nexti[0]); ++k) {
		i = a+nexti[k];
		j = b+nextj[k];
		if (i >= 0 && i < n && j >= 0 && j < m
			&& GRID[i][j] && !visited[i][j]) {
			res += dfs(i, j);
		}
	}
	return res;
}

int main(int argc, char *argv[])
{
	int i, j, res;
	while (scanf("%d%d", &n, &m) == 2) {
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				scanf("%d", &GRID[i][j]);
			}
		}

		memset(visited, 0, sizeof(visited));
		res = 0;
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				if (GRID[i][j] && !visited[i][j]) {
					int n = dfs(i, j);
					if (n > res)
						res = n;
				}
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
