#include <iostream>
#include <string>
using namespace std;

class Base {
private:
    int xx{ 0 };

protected:
    int index{ 0 };
    int x{ 0 };
    int y{ 0 };

public:
    int z{ 0 };
    string name_{ "BaseName"};

    Base() {cout << "Create Base " << name_ << endl; }
    ~Base() {cout << "Drop Base" << endl; }

    void BaseFunc() {cout << "Call BaseFunc\n";}
};

class BaseA: public Base
{
public:
    string name_{"AName"};

    BaseA() {cout << "From "          << Base::name_
                  << " Create BaseA " << name_       << endl; }
    ~BaseA() {cout << "Drop BaseA" << endl; }

    void AFunc() {cout << "Call AFunc\n" << endl;}
};

int main()
{
    Base b;
    cout << sizeof(b) << ":" << &b << endl;

    BaseA a;
    cout << sizeof(a) << ":" << &a << endl;
}
