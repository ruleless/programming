#include <iostream>
#include "Foo.h"
#include "rpc_server.h"

using namespace foo;

class Foo : public FooIf
{
  public:
    Foo() {}
    virtual ~Foo() {}

    virtual void echoVoid()
    {
        // sleep(5);
        std::cout<<"echoVoid: hello world"<<std::endl;
    }
    virtual void echoStr(std::string& _return)
    {
        _return = "hello world";
        std::cout<<"echoStr"<<std::endl;
    }
};

PROCESSOR_REGISTER("foo", FooProcessor, Foo);
