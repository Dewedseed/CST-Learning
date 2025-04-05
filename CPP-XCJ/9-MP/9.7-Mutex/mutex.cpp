#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

static mutex mux_;

void TestMutex() {
    thread ths[3];
    for (auto &th : ths) {
        th = thread([]{
            while (true) {
                // mux_.lock();
                { lock_guard<mutex> lock(mux_);
                cout << "-----------------------------------" << endl;
                cout << this_thread::get_id() << endl;
                cout << "1--------------------" << endl;
                cout << "2--------------------" << endl;
                cout << "3--------------------" << endl;
                cout << "4--------------------" << endl;
                cout << endl; }
                // mux_.unlock();
                std::this_thread::sleep_for(100ms);
            }
        });
    }
    for (auto &th : ths)
        th.join();
}

int main()
{
    TestMutex();
}
