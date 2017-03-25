#include "utest.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cppunit/extensions/TestFactoryRegistry.h"
#include "cppunit/ui/text/TestRunner.h"

CPPUNIT_TEST_SUITE_REGISTRATION(UTest);

//--------------------------------------------------------------------------
#ifndef min
# define min(a, b) ((a) <= (b) ? (a) : (b))
#endif
#ifndef max
# define max(a, b) ((a) >= (b) ? (a) : (b))
#endif 

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
	char *fa = (char *)malloc(a_len+1);
	char *fb = (char *)malloc(b_len+1);
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
	char *fa = (char *)malloc(a_len+1);
	char *fb = (char *)malloc(b_len+1);
	char *tempres = (char *)malloc(a_len+b_len+2), *ptr;
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
//--------------------------------------------------------------------------

UTest::UTest()
{}

UTest::~UTest()
{}
	
void UTest::setUp()
{}
	
void UTest::tearDown()
{}

void UTest::testAdd()
{
	srand(time(NULL));
	int testTimes = 600;
	char sa[256], sb[256], sc[256], log[256];
	while (testTimes--)
	{
		int a = rand()%65535, b = rand()%65535;
		snprintf(sa, sizeof(sa), "%d", a);
		snprintf(sb, sizeof(sb), "%d", b);
		add(sa, sb, sc);
		snprintf(log, sizeof(log), "%s+%s == %s should be %d", sa, sb, sc, a+b);
		CPPUNIT_ASSERT_MESSAGE(log, atoi(sc) == a+b);
	}
}

void UTest::testMul()
{
	srand(time(NULL));
	int testTimes = 600;
	char sa[256], sb[256], sc[256], log[256];
	while (testTimes--)
	{
		int a = rand()%65535, b = rand()%65535;
		snprintf(sa, sizeof(sa), "%d", a);
		snprintf(sb, sizeof(sb), "%d", b);
		mul(sa, sb, sc);
		snprintf(log, sizeof(log), "%s*%s == %s should be %d", sa, sb, sc, a*b);
		CPPUNIT_ASSERT_MESSAGE(log, atoi(sc) == a*b);
	}
}

int main(int argc, char *argv[])
{
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(CppUnit::TestFactoryRegistry::getRegistry().makeTest());
	runner.run();
	
	exit(0);
}
