#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//--------------------------------------------------------------------------
namespace situation1
{
class Obj
{
  public:
    Obj(const char *desc)
	{
		strncpy(mDesc, desc, 256);
		printf("default construct %p \"%s\"\n", (void *)this, mDesc);
	}
    virtual ~Obj()
	{
		printf("~ destruct %p \"%s\"\n", (void *)this, mDesc);
	}
  private:
	char mDesc[256];
};

void testFunc1(const Obj &i)
{	
}
}
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// Situation 3.
namespace situation3
{
class Obj
{
  public:
    Obj(int i = 0) : a(i)
	{
		printf("default construct %p %d\n", (void *)this, a);
	}

	Obj(const Obj &obj)
	{
		a = obj.a;
		printf("copy construct %p %d\n", (void *)this, a);
	}

	Obj& operator= (const Obj &o)
	{
		a = o.a;
		printf("operator= %p %d\n", (void *)this, a);
		return *this;
	}
	
    virtual ~Obj()
	{
		printf("~ destruct %p %d\n", (void *)this, a);
	}

	void set(int i)
	{
		a = i;
	}
  private:
	int a;
};

Obj testFunc1()
{
	Obj o(1);
	o.set(1);
	return o;
}

Obj testFunc2()
{
	return Obj(2); // it's called RVO(Return Value Optimization)
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
		printf("situation 3 begin\n");
		using namespace situation3;
		Obj o1 = testFunc1();
		Obj o2 = testFunc2();
		printf("situation 3 end\n");
	}
#ifndef unix
	getchar();
#endif	
    return 0;
}
