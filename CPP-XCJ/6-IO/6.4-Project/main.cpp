#include <iostream>
#include "log.h"
using namespace std;

int main()
{
    LogInit(LogType::Console);
    LOGDEBUG("测试日志 DEBUG");
    LOGINFO ("测试日志 INFO");
    LOGERROR("测试日志 ERROR");
    LOGFATAL("测试日志 FATAL");

    LogInit(LogType::Console,
            "{time} {content} {file}:{line}",
            "log.txt");
    LOGDEBUG("测试日志 DEBUG - CONSOLE");
    LOGINFO ("测试日志 INFO  - CONSOLE");
    LOGERROR("测试日志 ERROR - CONSOLE");
    LOGFATAL("测试日志 FATAL - CONSOLE");

    LogInit(LogType::File,
            "{time} |{level}|{content}|{file}:{line}",
            "log.txt");
    LOGDEBUG("测试日志 DEBUG - CONSOLE");
    LOGINFO ("测试日志 INFO  - CONSOLE");
    LOGERROR("测试日志 ERROR - CONSOLE");
    LOGFATAL("测试日志 FATAL - CONSOLE");
}
