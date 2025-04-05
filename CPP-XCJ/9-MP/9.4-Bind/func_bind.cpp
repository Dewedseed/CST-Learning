#include <iostream>
#include <string>
#include <functional>

using namespace std;

int TestBind(int x, int y, string str, int count) {
    cout << x << ":" << y << " " << str << " " << count << endl;
    return 0;
}

void TestBind_G() {
    using namespace placeholders;

    auto bfunc1 = std::bind(TestBind, 100, 200, std::placeholders::_1, _2);
    bfunc1("Test Bind function 1", 999);

    auto bfunc2 = std::bind(TestBind, 100, 200, _2, _1);
    bfunc2(156, "Test Bind function 2");
}

class MyClass {
public:
    MyClass () {
        func_ = std::bind(&MyClass::Test, this, std::placeholders::_1);
    }

    int Test(string str) {
        cout << "Data Test: " << str << endl;
        return 0;
    }

    void Call() {
        func_("bind call this");
    }

    void SetFunc(function<int(string)> f) {
        func_ = f;
    }

private:
    function<int(string)> func_;
};

void TestBind_L() {
    using namespace placeholders;

    MyClass mc;
    auto lfunc = std::bind(&MyClass::Test, &mc, _1);
    lfunc("MyClass");

    mc.Call();

    auto bfunc = std::bind(TestBind, 100, 200, _1, 666);
    mc.SetFunc(bfunc);

    mc.Call();
}

int main()
{
    TestBind_G();
    TestBind_L();
}
