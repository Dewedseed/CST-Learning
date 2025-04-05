#include <functional>
#include <iostream>
#include <string>
using namespace std;

class Data {
public:
    void Test() {cout << "Data Test " << endl;}
    void Call(function<void()> func) {func();}
    void TestCall () {
        function<void()> func = [this] {
            Test();
            };
        func();
    }
};

void Test() {cout << __FUNCTION__ << endl;}

void TestLambda() {
    // format 1
    auto func1 = []{cout << "test lambda" << endl;};
    func1();
    // format 2
    []{cout << "test lambda2" << endl;}();
    // format 3
    auto func2 = [](int x, int y, string str) {
        cout << "lambda " << x << ":" << y << " " << str << endl;
        };
    func2(100, 200, "test");
    // format 4
    auto func3 = []{return 999;};
    cout << func3() << endl;
    // format 5
    auto func4 = []()->string {return "test return";};
    auto str = func4();
    // format 6
    auto func5 = [](auto s) {cout << s << endl;};
    func5(1);
    func5("test");
    // format 7
    int x = 100;
    cout << "&x = " << &x << endl;
    [=](){
        cout << "&x = " << &x << endl;
        }();
    // format 8
    [&](){
        cout << "&x = " << &x << endl;
        }();
    // format 9
    int w = 100, h = 200;
    cout << "&w = " << &w << endl;
    cout << "&h = " << &h << endl;
    [=, &h] {
        cout << "&w = " << &w << endl;
        cout << "&h = " << &h << endl;
    }();
}

void TestLambda_L() {
    Data data;
    auto cfunc = [&data] {data.Test();};
    cfunc();

    data.TestCall();
    data.Call(Test);
    data.Call([]{cout << "Test data call" << endl;});
}

int main()
{
    // TestLambda();
    TestLambda_L();
}
