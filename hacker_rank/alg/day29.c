#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int t, n, k;
	scanf("%d", &t);
	while (t--) {
		int i, j, res = 0, tmp;

		scanf("%d%d", &n, &k);
		for (i = 1; i <= n-1; ++i) {
			for (j = i+1; j <= n; ++j) {
				tmp = i&j;
				if (tmp < k && tmp > res)
					res = tmp;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
