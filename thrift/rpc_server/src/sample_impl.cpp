#include <iostream>
#include "Sample.h"
#include "rpc_server.h"

using namespace sample;

class Sample : public SampleIf
{
  public:
    Sample() {}
    virtual ~Sample() {}

    virtual void echoStruct(TestStruct& _return)
    {
        _return.num1 = 1;
        _return.num2 = 2;
        _return.comment = "sample test";
    }
};

PROCESSOR_REGISTER("sample", SampleProcessor, Sample);
