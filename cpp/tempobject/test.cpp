#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

//--------------------------------------------------------------------------
Obj testFunc1()
{
	Obj o(1);
	o.set(1);
	return o;
}

//--------------------------------------------------------------------------
Obj testFunc2()
{
	return Obj(2); // it's called RVO(Return Value Optimization)
}

int main(int argc, char *argv[])
{
    Obj o1 = testFunc1();
	Obj o2 = testFunc2();
	getchar();
    return 0;
}
