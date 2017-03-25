#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long INT64;

int is_kaprekar_numbers(int n) {
	INT64 square = (INT64)n*n;
	INT64 k = 1;
	while (n / k) {		
		k *= 10;
	}
	return square/k + square%k == n;
}

int main(int argc, char *argv[])
{
	int p, q;
	while (scanf("%d%d", &p, &q) != EOF) {
		int n, found = 0;
		for (n = p; n <= q; ++n) {
			if (is_kaprekar_numbers(n)) {
				printf("%d ", n);
				found = 1;
			}
		}

		if (!found)
			puts("INVALID RANGE");
	}
	return 0;
}
