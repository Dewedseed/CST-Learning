/*
log module requirement
(1) Input format: `LOGDEBUG("test log 001")`
(2) Generate log: `2025-04-03 10:11:12 debug:test log 001 main.cpp:20`
(3) Log stream: console / string / file
(4) Other: logLevel
*/
#pragma once
#include <string>

enum class LogType {
    Console, File
};

enum class LogLevel {
    DEBUG, INFO, ERROR, FATAL
};


/*
Initial log system.
@para logtype console/file
@para format {time}{content}{file}:{line}
@para para filename / ip
@return initial state
*/
bool LogInit(LogType logtype = LogType::Console,
             std::string format = "{time} {content} {file}:{line}",
             std::string para = "log.txt");


/*
Write log to console or file.
@para level log level (debug/info/error/fatal)
@para log   log content
@para file  exe file
@para line  file line
*/
void LogWrite(LogLevel level, std::string log, std::string file, int line);

#define LOGDEBUG(s)  LogWrite(LogLevel::DEBUG, s, __FILE__, __LINE__)
#define LOGINFO(s)   LogWrite(LogLevel::INFO,  s, __FILE__, __LINE__)
#define LOGERROR(s)  LogWrite(LogLevel::ERROR, s, __FILE__, __LINE__)
#define LOGFATAL(s)  LogWrite(LogLevel::FATAL, s, __FILE__, __LINE__)
