#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

unsigned get_bit_num(unsigned n) {
	unsigned sum = 0;
	while (n) {
		if (n & 1)
			++sum;
		n >>= 1;
	}
	return sum;
}

unsigned long long get_range_bit_num(unsigned n) {
	if (0 == n)
		return 0;

	if (n % 2 == 0) {
		return get_range_bit_num(n-1) + get_bit_num(n);
	}

	return 2*get_range_bit_num(n>>1) + (n>>1) + 1;
}

unsigned long long get_negative_range_bit_num(int n) {
	assert(n < 0);

	unsigned negative = (unsigned)n;
	unsigned max = (unsigned)-1;
	return get_range_bit_num(max)-get_range_bit_num(negative-1);
}

int main(int argc, char *argv[])
{
	int t, low, high;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &low, &high);

		unsigned long long sum_bits = 0;

		if (high < 0) {
			sum_bits = get_negative_range_bit_num(low)-
					   (high+1 < 0 ? get_negative_range_bit_num(high+1) : 0);
		} else if (low < 0) {
			sum_bits = get_negative_range_bit_num(low)+get_range_bit_num(high);
		} else {
			sum_bits = get_range_bit_num(high)-get_range_bit_num(low > 0 ? low-1 : 0);
		}

		printf("%llu\n", sum_bits);
	}
	return 0;
}
