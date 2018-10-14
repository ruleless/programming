#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Base
{
  public:
    Base() : b_(1) { }
    virtual ~Base() { }

    string show()
    {
        ostringstream os;
        os << __FUNCTION__ << " b_ in Base: " << b_ << endl;
        return os.str();
    }

    virtual string display()
    {
        ostringstream os;
        os << __FUNCTION__ << " b_ in Base: " << b_ << endl;
        return os.str();
    }

    static void sfunc() { }

  protected:
    int b_;
};

class Child : public Base
{
  public:
    Child() : Base(), b_(2) { }
    virtual ~Child() { }

    string show()
    {
        ostringstream os;
        os << __FUNCTION__ << " b_ in Child: " << b_ << endl;
        return os.str();
    }

    virtual string display()
    {
        ostringstream os;
        os << __FUNCTION__ << " b_ in Child: " << b_ << endl;
        return os.str();
    }

    static void sfunc() { }

  private:
    int b_;
};

int main(int argc, char *argv[])
{
    Base *p;
    Child c;

    p = &c;
    cout << "Call nonstatic member function by 'p': " << p->show();
    cout << "Call nonstatic member function by 'c': " << c.show();
    cout << "Call virtual member function: " << p->display();

    return 0;
}
