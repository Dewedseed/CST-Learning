#include <iostream>
#include <string>
#include <thread>
#include <future>
#include <mutex>
#include <string>

using namespace std;

void TestAsync() {
    future<string> fut1 = async([]()->string {return "test async";});

    auto fut2 = async([]{
        for (int i = 0; i < 3; ++i) {
            this_thread::sleep_for(1s);
            cout << "Wait..." << endl;
        }
        cout << "async future" << endl;
        return 999;
    });
    cout << fut2.get() << endl;
    cout << "end future get" << endl;
}

int main()
{
    TestAsync();
}
