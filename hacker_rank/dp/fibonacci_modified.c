#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef min
# define min(a, b) ((a) <= (b) ? (a) : (b))
#endif
#ifndef max
# define max(a, b) ((a) >= (b) ? (a) : (b))
#endif

#define MAX_NUM 131072

char *reverse(char *str) {
	char *ptr = str, *endptr = str, tmp;
	while (*endptr)
		endptr++;
	if ('\0' == *endptr)
		endptr--;
	while (ptr < endptr) {
		tmp = *ptr;
		*ptr = *endptr;
		*endptr = tmp;
		ptr++;
		endptr--;
	}
	return str;
}

char *add(char *a, char *b, char *res) {	
	if (strlen(a) == 0 || strlen(b) == 0) {
		*res = '\0';
		if (strlen(a) > 0)
			strcpy(res, a);
		if (strlen(b) > 0)
			strcpy(res, b);
		return res;
	}

	int a_len = strlen(a), b_len = strlen(b);
	static char fa[MAX_NUM];
	static char fb[MAX_NUM];
	char *ptr = res;
	strcpy(fa, a);
	strcpy(fb, b);
	reverse(fa);
	reverse(fb);

	*ptr = '\0';
	int flag = 0, i, u, v;
	for (i = 0; i < max(a_len, b_len); ++i) {
		u = i < a_len ? fa[i]-'0' : 0;
		v = i < b_len ? fb[i]-'0' : 0;
		*ptr++ = (u+v+flag)%10+'0';
		flag = (u+v+flag)/10;
	}
	if (flag)
		*ptr++ = flag+'0';
	*ptr = '\0';
	reverse(res);
	return res;
}

char *mul(char *a, char *b, char *res) {
	*res = '\0';
	if (strlen(a) == 0 || strlen(b) == 0) {
		*res++ = '0';
		*res = '\0';
		return res;
	}

	int a_len = strlen(a), b_len = strlen(b);
	static char fa[MAX_NUM];
	static char fb[MAX_NUM];
	static char tempres[MAX_NUM];
	char *ptr;
	strcpy(fa, a);
	strcpy(fb, b);
	reverse(fa);
	reverse(fb);
	
	int flag = 0, i, j, u, v;
	for (i = 0; i < a_len; ++i) {
		ptr = tempres;
		for (j = 0; j < i; ++j)
			*ptr++ = '0';
		*ptr = '\0';
		for (j = 0; j < b_len; ++j) {
			u = fa[i]-'0';
			v = fb[j]-'0';
			*ptr++ = (u*v+flag)%10+'0';
			flag = (u*v+flag)/10;
		}
		if (flag)
			*ptr++ = flag+'0';
		*ptr = '\0';
		flag = 0;
		reverse(tempres);
		add(tempres, res, res);
	}
	return res;
}

#define N 30
static char s_fib[N][MAX_NUM];
char *fib(int n) {
	if (n <= 2 || strlen(s_fib[n]) > 0)
		return s_fib[n];

	char tmpres[MAX_NUM] = {0};
	mul(fib(n-1), fib(n-1), tmpres);
	add(tmpres, fib(n-2), s_fib[n]);
	return s_fib[n];
}

int main(int argc, char *argv[])
{
	int n;
#if 1
	scanf("%s%s%d", s_fib[1], s_fib[2], &n);	
	printf("%s\n", fib(n));
#else
	char a[512], b[512], c[512];
	while (scanf("%s%s", a, b) == 2) {
		printf("%s\n", mul(a, b, c));
	}
#endif
	return 0;
}
