#include <cstdio>
#include<iostream>
#include <cmath>
using namespace std;

int main() {
	double a, x;
	int l,k ;
	scanf( "%lf%d",&a,&l);
	int beg[2], end[2], mid[2];
	beg[0] = 0, beg[1] = 1;
	end[1] = 0, end[0] = 1;
	mid[0] = 1, mid[1] = 1;
	while(mid[0] <= l && mid[1] <= l) {
		x = 1.0 * mid[0] / mid[1];
		if(x > a) {
			end[0] = mid[0];
			end[1] = mid[1];
		} else {
			beg[0] = mid[0];
			beg[1] = mid[1];   
		}
		mid[0] = beg[0] + end[0];
		mid[1] = beg[1] + end[1];
	}
	k = 1;
	if(end[1] == 0) k = 0;
	if(k) {
		if( fabs(1.0 * beg[0] / beg[1] - a) < fabs(1.0 * end[0] / end[1] - a) ) k = 0;
	}
	if(k == 0) {
		printf("%d %d\n", beg[0], beg[1]);
	} else {
		printf("%d %d\n", end[0], end[1]);
	}
	return 0;
}
