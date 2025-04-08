#include "test_class_in.h"
#include "log_fac.h"
#include "logger.h"

void TestClassIn::TestXLog()
{
    // LOGDEBUG("debug");
    LogFac::Instance().logger().Write(LogLevel::DEBUG, "sdad", __FILE__, __LINE__);
}
