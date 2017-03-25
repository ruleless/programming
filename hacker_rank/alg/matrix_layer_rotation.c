#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 301
#define M 301

static int array[N*M], dummy[N*M];
void rotate_array(int n, int r) {
	if (r%n == 0)
		return;

	memcpy(dummy, array, n*sizeof(int));

	int i;
	for (i = 0; i < n; ++i) {
		array[i] = dummy[(i+r) % n];
	}	
}

static int matrix[M][N];
void rotate_matrix(int k, int nr, int nc, int r) {
	if (nr < 2 || nc < 2)
		return;

	int n = (nr+nc-2)*2;
	int real_rotate_times = r % n;
	if (0 == real_rotate_times)
		return;

	int i, j, index = 0;
	for (i = k; i < k+nr; ++i)
		array[index++] = matrix[i][k];	
	for (j = k+1; j < k+nc; ++j)
		array[index++] = matrix[k+nr-1][j];
	for (i = k+nr-2; i >= k; --i)
		array[index++] = matrix[i][k+nc-1];
	for (j = k+nc-2; j > k; --j)
		array[index++] = matrix[k][j];
	
	rotate_array(n, n-real_rotate_times);

	index = 0;
	for (i = k; i < k+nr; ++i)
		matrix[i][k] = array[index++];	
	for (j = k+1; j < k+nc; ++j)
		matrix[k+nr-1][j] = array[index++];
	for (i = k+nr-2; i >= k; --i)
		matrix[i][k+nc-1] = array[index++];
	for (j = k+nc-2; j > k; --j)
		matrix[k][j] = array[index++];

	rotate_matrix(k+1, nr-2, nc-2, r);
}

int main(int argc, char *argv[])
{
	int m, n, r;
	
	while (scanf("%d%d%d", &m, &n, &r) == 3) {
		int i, j;

		for (i = 0; i < m; ++i) {
			for (j = 0; j < n; ++j) {
				scanf("%d", &matrix[i][j]);
			}
		}

		rotate_matrix(0, m, n, r);

		for (i = 0; i < m; ++i) {
			for (j = 0; j < n; ++j) {
				if (j < n-1)					
					printf("%d ", matrix[i][j]);
				else
					printf("%d\n", matrix[i][j]);
			}
		}
	}		
	return 0;
}
