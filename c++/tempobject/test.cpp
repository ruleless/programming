#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Obj
{
  public:
    Obj(const char *desc)
	{
		strncpy(mDesc, desc, 256);
		printf("default construct %p \"%s\"\n", (void *)this, mDesc);
	}

	Obj(const Obj &o)
	{
		strncpy(mDesc, o.mDesc, 256);
		printf("copy construct %p \"%s\"\n", (void *)this, mDesc);
	}

	Obj& operator= (const Obj &o)
	{
		strncpy(mDesc, o.mDesc, 256);
		printf("operator= %p \"%s\"\n", (void *)this, mDesc);
		return *this;
	}
	
    virtual ~Obj()
	{
		printf("~ destruct %p \"%s\"\n", (void *)this, mDesc);
	}	
  private:
	char mDesc[256];
};

//--------------------------------------------------------------------------
// Situation 1.
namespace situation1
{
void testFunc1(const Obj &i)
{	
}
}
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// Situation 2.
namespace situation2
{
void testFunc1(Obj i)
{
}
}
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// Situation 3.
namespace situation3
{
Obj testFunc1()
{
	Obj o("test1");
	return o;
}

Obj testFunc2()
{
	return Obj("test2"); // it's called RVO(Return Value Optimization)
}
}
//--------------------------------------------------------------------------

int main(int argc, char *argv[])
{
	{
		printf("situation 1 begin\n");
		using namespace situation1;
		testFunc1("test situation 1");
		printf("situation 1 end\n");
	}
	puts("");
	{
		printf("situation 2 begin\n");
		using namespace situation2;
		Obj o("situation 2");
		testFunc1(o);
		printf("situation 2 end\n");
	}
	puts("");
	{
		printf("situation 3 begin\n");
		using namespace situation3;
		Obj o1 = testFunc1();
		Obj o2 = testFunc2();
		Obj o3 = o1;
		o3 = o2;
		printf("situation 3 end\n");
	}
#ifndef unix
	getchar();
#endif	
    return 0;
}
