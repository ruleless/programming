#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int is_primer(int n) {
	if (n <= 1) {
		return 0;
	}
	
	int square = (int)sqrt(n), i;
	for (i = 2; i <= square; ++i) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main(int argc, char *argv[]) {
	int testcnt;
	scanf("%d", &testcnt);
	
	while (testcnt--)
	{
		int n;
		scanf("%d", &n);
		printf("%s\n", is_primer(n) ? "Prime" : "Not prime");
	}
	return 0;
}
