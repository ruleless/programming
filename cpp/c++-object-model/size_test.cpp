#include <iostream>

using namespace std;

class X { };
class Y : virtual public X { };
class Z : virtual public X { };
class A : public Y, public Z { };

int main(int argc, char *argv[])
{
    cout << "X: " << sizeof(X) << endl;
    cout << "Y: " << sizeof(Y) << "  Z: " << sizeof(Z) << endl;
    cout << "A: " << sizeof(A) << endl;
    return 0;
}
