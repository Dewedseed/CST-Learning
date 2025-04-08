/*
Requirement:
(1) Configure: file
(2) Scalable: design principle
(3) Safety: memory, thread
*/
#include <iostream>
#include "log_fac.h"
#include "test_class.h"

using namespace std;

int main()
{
    LogFac::Instance().Init();

    LOGDEBUG("Test log debug");
    LOGINFO ("Test log info");
    LOGERROR("Test log error");
    LOGFATAL("Test log fatal");

    TestClass tc;
    tc.TestXLog();

    return 0;
}
