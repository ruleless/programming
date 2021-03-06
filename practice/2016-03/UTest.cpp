#include "UTest.h"
#include "BSearch.hpp"
#include "QSort.hpp"
#include "MSort.hpp"
#include "Trie.h"
#include "AdjList.hpp"
#include "Dijkstra.hpp"
#include "strstr.hpp"

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

void UTest::test_adjlist()
{
	static const int N = 10;
	typedef alg::AdjList<N, N*N, float> TAdjList;
	TAdjList a;
	a.addEdge(0, 1, 10.7);
	a.addEdge(0, 2, 100.1);
	a.addEdge(1, 5, 10.3);
	a.addEdge(2, 6, 1);
	for (int i = 0; i < N; ++i)
	{
		printf("%d:", i);
		for (TAdjList::TEdge *e = a.v[i]; e != NULL; e = e->next)
		{
			printf("(%d, %f)", e->to, e->w);
		}
		printf("\n");
	}
}

void UTest::test_dijkstra()
{
	static const int N = 10;
	typedef alg::AdjList<N, N*N, float> TAdjList;
	TAdjList a;
	a.addEdge(0, 1, 10.7);
	a.addEdge(0, 2, 100.1);
	a.addEdge(1, 2, 10.2);

	float res[N];
	for (int i = 0; i < N; ++i)
		res[i] = 99999999.f;
	alg::dijkstra<float, 3>(3, a.v, 0, res);
	for (int i = 0; i < 3; ++i)
		printf("res[%d]=%f\n", i, res[i]);
}

void UTest::test_strstr()
{
	CPPUNIT_ASSERT(alg::strstr("abcdef", "abcdefg") == -1);
	CPPUNIT_ASSERT(alg::strstr("abcdef", "a") == 0);
	CPPUNIT_ASSERT(alg::strstr("abcdef", "abc") == 0);
	CPPUNIT_ASSERT(alg::strstr("abcdef", "bcd") == 1);
	CPPUNIT_ASSERT(alg::strstr("abcdef", "be") == -1);
}
