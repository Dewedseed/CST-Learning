#include <iostream>
using namespace std;

class MyClass
{
private:
    static int count; // declear
    static inline void AddCount() {
        ++count;
        ++size;
        cout << "AddCount count = " << count << endl;
        cout << "AddCount size = " << size << endl;
    }

public:
    static int size; // declear
    static inline void AddSize() {
        ++count;
        ++size;
        cout << "AddSize count = " << count << endl;
        cout << "AddSize size = " << size << endl;
    }

    // singleton
    static MyClass& Instance() {
        static MyClass mc;
        return mc;
    }

    // Encapsulation
    static void RunStatic(MyClass& obj) {
        obj.AddCount();
    }
};

int MyClass::count{ 0 }; // define
int MyClass::size{ 0 }; // define

int main()
{
    MyClass mcf;

    ++MyClass::size;
    cout << "MyClass::size = " << MyClass::size << endl;
    cout << "mcf::size = "     << mcf.size      << endl;

    MyClass::AddSize();
    mcf.AddSize();

    MyClass::Instance().AddSize();
}
