#include "cppunit/TestFixture.h"
#include "cppunit/extensions/HelperMacros.h"

class UTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(UTest);
	CPPUNIT_TEST(test_bsearch);
	CPPUNIT_TEST(test_qsort);
	CPPUNIT_TEST_SUITE_END();
  public:
    UTest();
    virtual ~UTest();
	
	virtual void setUp();
	
	virtual void tearDown();

	void test_bsearch();
	void test_qsort();
};
