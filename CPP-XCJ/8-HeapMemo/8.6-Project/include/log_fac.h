#pragma once

#include "logger.h"

#include <string>

/// Log Builder
class LogFac
{
public:
    static LogFac& Instance() {
        static LogFac fac;
        return fac;
    }

    /// @para con_file configure file
    void Init(const std::string& con_file = "log.conf");

    Logger& logger() {return logger_;}

private:
    LogFac(){}

    Logger logger_;
};

#define XLOGOUT(l,s) LogFac::Instance().logger().Write(l, s, __FILE__, __LINE__)
#define LOGDEBUG(s)  XLOGOUT(LogLevel::DEBUG, s)
#define LOGINFO(s)   XLOGOUT(LogLevel::INFO,  s)
#define LOGERROR(s)  XLOGOUT(LogLevel::ERROR, s)
#define LOGFATAL(s)  XLOGOUT(LogLevel::FATAL, s)
