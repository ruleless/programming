#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef max
# define max(a, b) ((a) > (b) ? (a) : (b))
#endif

int main(int argc, char *argv[])
{
	int return_year, return_month, return_day;
	int expected_year, expected_month, expected_day;
	
	while (scanf("%d%d%d", &return_day, &return_month, &return_year) == 3 &&
		   scanf("%d%d%d", &expected_day, &expected_month, &expected_year) == 3) {
		int fine = -1;

		if (return_year < expected_year) {
			fine = 0;
		} else if (return_year == expected_year) {
			if (return_month < expected_month) {
				fine = 0;
			} else if (return_month == expected_month) {
				fine = max(0, return_day-expected_day) * 15;
			} else {
				fine = (return_month-expected_month) * 500;
			}			
		} else {
			fine = 10000;
		}

		printf("%d\n", fine);
	}
	
	return 0;
}
