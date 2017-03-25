#include "cppunit/TestFixture.h"
#include "cppunit/extensions/HelperMacros.h"

class UTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(UTest);
	CPPUNIT_TEST(testAdd);
	CPPUNIT_TEST(testMul);
	CPPUNIT_TEST_SUITE_END();
  public:
    UTest();
    virtual ~UTest();
	
	virtual void setUp();
	
	virtual void tearDown();

	void testAdd();
	void testMul();
};
