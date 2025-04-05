#include <iostream>
#include <string>

using namespace std;

int TestFuncPtr(string str) {
    cout << "Call TestFuncPtr " << str << endl;
    return 0;
}

using FuncType = int(*)(string);

void TestGlobalFuncPtr() {
    TestFuncPtr("Para1");

    auto FuncPtr = TestFuncPtr;
    FuncPtr("Para2");

    int (*fun_ptr)(string);
    fun_ptr = TestFuncPtr;
    fun_ptr("para3");

    FuncType fptr1 = TestFuncPtr;
    fptr1("para4");
}

class MyClass {
public:
    using LocalCFun = int(MyClass::*)(string);

    MyClass() {
        func_ = &MyClass::Test;
    }

    int Test(string str) {
        cout << "MyClass::Test" << str << endl;
        return 0;
    }

    void Call() {
        (this->*func_)("para call");
    }

private:
    LocalCFun func_{nullptr};
};

using CFun = int(MyClass::*)(string);
void TestLocalFuncPtr() {
    auto cfun = &MyClass::Test;
    MyClass mc;
    (mc.*cfun)("para auto cfun");

    CFun cfun2 = &MyClass::Test;
    (mc.*cfun)("para using");

    mc.Call();
}

int main()
{
    TestGlobalFuncPtr();
    TestLocalFuncPtr();
}
