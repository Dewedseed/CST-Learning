#include <iostream>
#include <memory>
using namespace std;

class Data {
public:
    Data() {cout << "Create Data\n";}
    ~Data() {cout << "Drop Data\n";}

    void Print() {cout << "Print Data\n";}
};

void TestData() {
    unique_ptr<Data> ptr1(new Data);
    auto ptr2 = make_unique<Data>();

    ptr2->Print();
    (*ptr2).Print();

    auto ptr2_ptr = ptr2.get();
    ptr2_ptr->Print();

    auto ptr3 = make_unique<Data>();
    ptr3.reset(new Data);
    cout << "------------" << endl;

    auto ptr4  = make_unique<Data>();
    auto ptr4_ptr = ptr4.release();
    cout << "------------" << endl;

    auto ptr5 = make_unique<Data>();
    auto ptr6 = move(ptr5);
}

int main()
{
    TestData();
}
