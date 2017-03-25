#include "cppunit/TestFixture.h"
#include "cppunit/extensions/HelperMacros.h"

class UTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(UTest);
	CPPUNIT_TEST(test_bsearch);
	CPPUNIT_TEST(test_qsort);
	CPPUNIT_TEST(test_msort);
	CPPUNIT_TEST(test_trie);
	CPPUNIT_TEST(test_combination);
	CPPUNIT_TEST(test_adjlist);
	CPPUNIT_TEST(test_dijkstra);
	CPPUNIT_TEST(test_strstr);
	CPPUNIT_TEST_SUITE_END();	
  public:
    UTest();
    virtual ~UTest();
	
	virtual void setUp();
	
	virtual void tearDown();

	void test_bsearch();
	void test_qsort();
	void test_msort();
	void test_trie();
	void test_combination();

	void test_adjlist();
	void test_dijkstra();

	void test_strstr();
};
