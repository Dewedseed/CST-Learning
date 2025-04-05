#include <iostream>
using namespace std;

class XThread {
public:
    ~XThread(){cout << "Drop XThread" << endl;}
private:
    virtual void Run() = 0;
    void Start() {Run();}
};

class XTask:public XThread {
public:
    ~XTask(){cout << "Drop XTask" << endl;}
private:
    void Run() override {
        cout << "XTask Run" << endl;
    }
};

int main(){
    // XThread xt;
    XTask xta;
}
