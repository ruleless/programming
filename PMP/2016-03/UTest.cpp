#include "UTest.h"
#include "BSearch.hpp"
#include "QSort.hpp"
#include "MSort.hpp"
#include "Trie.h"

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

void UTest::test_qsort()
{
	int arr[] = {37281, 321, 321,5, -3123, 54353, 53, -132,};
	qSort(arr, 0, sizeof(arr)/sizeof(int)-1);
	for (int i = 0; i < sizeof(arr)/sizeof(int)-1; ++i)
	{		
		CPPUNIT_ASSERT(arr[i]<=arr[i+1]);
	}	
}

void UTest::test_msort()
{
	int arr[] = {37281, 321, 321,5, -3123, 54353, 53, -132,};
	mSort(arr, 0, sizeof(arr)/sizeof(int)-1);
	for (int i = 0; i < sizeof(arr)/sizeof(int)-1; ++i)
	{		
		CPPUNIT_ASSERT(arr[i]<=arr[i+1]);
	}	
}

void UTest::test_trie()
{
	Trie *root = trie_new();
	trie_insert(root, "test");
	trie_insert(root, "test");
	trie_insert(root, "test");
	CPPUNIT_ASSERT(trie_getword(root, "test") == 3);
	CPPUNIT_ASSERT(trie_getword(root, "test1") == 0);
	trie_destroy(root);
}

extern int getCombination(int m, int n);
void UTest::test_combination()
{
	printf("total count:%d\n", getCombination(5, 2));
	printf("total count:%d\n", getCombination(6, 2));
	printf("total count:%d\n", getCombination(6, 3));
}
