#include <iostream>
#include <memory>
#include <type_traits>
#include <utility>
using namespace std;

class Data {
public:
    Data() {cout << "Create Data\n";}
    ~Data() {cout << "Drop Data\n";}

    void Print() {cout << "Print Data\n";}
};


class DataPtr {
public:
    DataPtr(Data *d) {d_ = d;}
    ~DataPtr() {delete d_; d_ = nullptr;};

    // recovery default
    DataPtr() = default;
    // limit copy construct
    DataPtr(const DataPtr&) = delete;
    // limit copy assign
    DataPtr &operator = (const DataPtr&) = delete;

    // move construct
    DataPtr(DataPtr&& dp){
        d_ = dp.d_;
        dp.d_ = nullptr;
    }
    // move assign
    DataPtr &operator = (DataPtr && dp) {
        if (this == &dp) return *this;
        delete d_;
        d_ = dp.d_;
        dp.d_ = nullptr;
        return *this;
    }

    // inherent function
    Data* Get() {return d_;}
    Data* Release() {
        auto d = d_;
        d_ = nullptr;
        return d;
    }
    void Reset(Data* d)  {
        if (d == d_) return;
        delete d_; d_ = d;
    }

private:
    Data* d_{ nullptr };
};

void TestDataPtr() {
    DataPtr ptr1(new Data);

    // DataPtr ptr2 = ptr1;
    DataPtr ptr2;
    // ptr2 = ptr1;

    ptr1.Get()->Print();
    ptr1.Reset(new Data);
    auto p = ptr1.Release();
    p->Print();
    delete p;

    DataPtr ptr3 = move(ptr1);
    ptr3.Get()->Print();

    DataPtr ptr4;
    ptr4 = move(ptr3);
}

int main()
{
    TestDataPtr();
}
