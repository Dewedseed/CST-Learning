/*
Demand
1. log level: debug/info/error/fatal
*/

#include <iostream>
#include <string>
using namespace std;

enum class LogLevel
{
    DEBUG,
    INFO,
    ERROR,
    FATAL
};

// user control log level
int main(int argc, char *argv[])
{
    auto logLevel = LogLevel::DEBUG;
    // parse argument
    if (argc > 1)
    {
        string levelStr = argv[1];
        if (levelStr == "info")
            logLevel = LogLevel::INFO;
        else if (levelStr == "error")
            logLevel = LogLevel::ERROR;
        else if (levelStr == "fatal")
            logLevel = LogLevel::FATAL;
    }
    // test log
    {
        auto level = LogLevel::DEBUG;
        string context = "test log 1";
        if (level >= logLevel)
        {
            string strLevel;
            switch (level)
            {
                case LogLevel::DEBUG:
                    strLevel = "debug"; break;
                case LogLevel::INFO:
                    strLevel = "info"; break;
                case LogLevel::ERROR:
                    strLevel = "erro"; break;
                case LogLevel::FATAL:
                    strLevel = "fatal"; break;
            }
            cout << strLevel << ": " << context << endl;
        }
    }
}
