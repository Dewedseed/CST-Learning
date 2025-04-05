#include <iostream>
#include <string>
using namespace std;

class MyClass {
public:
    MyClass() {
        cout << "Create " << name_ << " " << index_ << endl;
    }

    MyClass(int) {};
    MyClass(int x, int y) {};

    explicit MyClass(char c){};

    ~MyClass() {
        cout << "Drop " << name_ << endl;
    }

    int index() {return index_;}
    void set_index(int i) {index_ = i;}

private:
    static int size_;
    string name_;
    int begin_{ 1 };
    int index_{ begin_ + size_++ };
};

int MyClass::size_{ 0 };

// global
// static MyClass mcg;

void TestStack() {
    cout << "Begin TestStack" << endl;

    // stack
    MyClass mc1;
    MyClass mc2;

    cout << "end TestStack" << endl;
}

void TestHeap() {
    cout << "Begin TestHeap" << endl;

    // heap
    MyClass* mcp1 = new MyClass();
    delete mcp1;
    mcp1 = nullptr;

    // auto mcp2 = new MyClass;

    cout << "end TestHeap" << endl;
}

void TestMyClassIn(MyClass mc) {}

void TestConstruct() {
    cout << "Begin TestConstruct" << endl;

    MyClass mc1;
    MyClass mc2(1);
    MyClass mc3(100, 100);
    MyClass mc4{ 2 }; // check
    MyClass mc5{ 200, 200 }; // check

    MyClass* mc6 = new MyClass(300, 300);
    delete mc6; mc6 = nullptr;

    MyClass* mc7 = new MyClass{400, 400};
    delete mc7; mc7 = nullptr;

    // implicit transfer
    MyClass mc8 = 10;
    MyClass mc9 = {1, 2};
    mc9 = 3;

    TestMyClassIn(mc8);
    TestMyClassIn(MyClass());
    TestMyClassIn(4);
    TestMyClassIn({3, 4});

    // explicit transfer
    MyClass mc0 = (MyClass) 1;

    MyClass mce1('a');
    MyClass mce2{'b'};

    // MyClass mce3 = 'c'; // must explicit
    // TestMyClassIn('d');
    TestMyClassIn((MyClass)'e');

    cout << "end TestConstruct" << endl;
}

int main()
{
    cout << "Begin main" << endl;

    TestStack();
    TestHeap();
    TestConstruct();

    cout << "end main" << endl;
}
