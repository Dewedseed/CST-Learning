#include <iostream>
#include <thread>
using namespace std;

void TestFunc(string str) {
    this_thread::sleep_for(100ms);
    cout << this_thread::get_id() << endl;
    cout << " Call TestFunc" << str << endl;
}


class Task {
public:
    void Run() {cout << "Task::Run()" << endl;}
    void Start() {
        th_ = thread(&Task::Run, this);
    }
    void Wait() {
        if (th_.joinable()) th_.join();
    }

private:
    thread th_;
};

void TestThread() {
    cout << "main thread " << this_thread::get_id() << endl;
    thread th1(
        []{cout << this_thread::get_id() << " Lambda thread\n";}
        );
    cout << "end begin thread" << endl;
    // th1.detach();
    th1.join();

    thread th2;
    th2 = thread(TestFunc, "test string");
    th2.join();

    Task task;
    thread th3(&Task::Run, &task);
    th3.join();

    task.Start();
    task.Wait();
}

int main()
{
    TestThread();
}
