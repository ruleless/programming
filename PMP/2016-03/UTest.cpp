#include "UTest.h"
#include "BSearch.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(UTest);

UTest::UTest()
{
}

UTest::~UTest()
{
}
	
void UTest::setUp()
{
}
	
void UTest::tearDown()
{
}

void UTest::test_bsearch()
{
	int arr[] = {-1, 3, 4, 7, 8, 9, 100, 10001,};
	CPPUNIT_ASSERT(bsearch(arr, 0, sizeof(arr)/sizeof(int), -1) == 0);
	CPPUNIT_ASSERT(bsearch(arr, 0, sizeof(arr)/sizeof(int), 3) == 1);
	CPPUNIT_ASSERT(bsearch(arr, 0, sizeof(arr)/sizeof(int), 4) == 2);
	CPPUNIT_ASSERT(bsearch(arr, 0, sizeof(arr)/sizeof(int), 7) == 3);
	CPPUNIT_ASSERT(bsearch(arr, 0, sizeof(arr)/sizeof(int), 8) == 4);
	CPPUNIT_ASSERT(bsearch(arr, 0, sizeof(arr)/sizeof(int), 10001) == 7);
	CPPUNIT_ASSERT(bsearch(arr, 0, sizeof(arr)/sizeof(int), 10002) == -1);
	CPPUNIT_ASSERT(bsearch(arr, 0, sizeof(arr)/sizeof(int), -3213) == -1);
}
