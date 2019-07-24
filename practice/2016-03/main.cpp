#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cppunit/extensions/TestFactoryRegistry.h"
#include "cppunit/ui/text/TestRunner.h"

int main(int argc, char *argv[])
{
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(CppUnit::TestFactoryRegistry::getRegistry().makeTest());
	runner.run();

	exit(0);
}
