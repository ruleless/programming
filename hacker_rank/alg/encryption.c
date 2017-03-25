#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BUF 100

void encrypt(const char *src, char *out) {
	int len = strlen(src);
	int square = (int)sqrt(len);
	int m = square, n = square;
	
	if (m*n < len)
		++n;
	if (m*n < len)
		++m;

	int i, j, index = 0;
	for (j = 0; j < n; ++j) {
		for (i = 0; i < m; ++i) {
			int k = i*n + j;
			if (k < len)
				out[index++] = src[k];
		}
		if (j < n-1)
			out[index++] = ' ';
	}
	out[index] = '\0';
}

int main(int argc, char *argv[])
{
	char buf[MAX_BUF], out[MAX_BUF*2];
	while (scanf("%s", buf) != EOF) {
		encrypt(buf, out);
		printf("%s", out);
	}
	return 0;
}
