#include <iostream>
#include <string>

using namespace std;

class Foo
{
  public:
    Foo(bool ok) : ok_(ok) {}
    virtual ~Foo() {}

    // 类型转换运算符
    operator bool()
    {
        return ok_;
    }

  private:
    bool ok_;
};

int main(int argc, char *argv[])
{
    Foo foo(false);
    if (!foo) {
        cout<<"foo: "<<foo<<endl;
    }
    return 0;
}
