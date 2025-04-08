#include <iostream>
#include <process.h>
#include <ratio>

#include "log_fac.h"
#include "x_exec.h"
#include "user_input.h"
#include "log_fac.h"

#include "xtask.h"
#include "xtask_fac.h"
#include "xvideo_input.h"

#include "test_class.h"
#include "test_class_in.h"

using namespace std;

void TestXlog(){

    UserInput user;

    user
        // parameter function register
        .Reg("-s", [](const string& s){
            cout << "src:" << s << endl;
        })
        .Reg("-d", [](const string& s){
            cout << "des:" << s << endl;
        })
        .Reg("-p", [](const string& s){
            cout << "password:" << s << endl;
        })
        // task function register
        .RegTask("cv", [](){
            cout << "cv task" << endl;
        });

    user.Start();
}

void TestXVideo() {
}

int main()
{
    // TestXlog();
    LogFac::Instance().Init();

    // TestClass tc;
    // tc.TestXLog();

    // TestClassIn tci;
    // tci.TestXLog();

    XVideoInput input;
    input.Start(XTaskFactory::Create());
}
