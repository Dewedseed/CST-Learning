#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <iomanip>
#include <string>

#include "log.h"

static std::ostream  logOut(std::cout.rdbuf());
static std::ofstream logFile;
static std::string   logIP     = "";
static std::string   logFormat = "";

/* Get current time */
static std::string GetNow(
    const char* fmt = "%Y-%m-%d %H:%M:%S",
    int time_zone = 8)
{
    std::time_t unix_sec = std::time(nullptr);
    std::tm tm;

    static const int kHoursInDay = 24;
    static const int kMinutesInHour = 60;
    static const int kDaysFromUnixTime = 2472632;
    static const int kDaysFromYear = 153;
    static const int kMagicUnkonwnFirst = 146097;
    static const int kMagicUnkonwnSec = 1461;

    tm.tm_sec = unix_sec % kMinutesInHour;
    int i = (unix_sec / kMinutesInHour);
    tm.tm_min = i % kMinutesInHour; //nn
    i /= kMinutesInHour;
    tm.tm_hour = (i + time_zone) % kHoursInDay; // hh
    tm.tm_mday = (i + time_zone) / kHoursInDay;

    int a = tm.tm_mday + kDaysFromUnixTime;
    int b = (a * 4 + 3) / kMagicUnkonwnFirst;
    int c = (-b * kMagicUnkonwnFirst) / 4 + a;
    int d = ((c * 4 + 3) / kMagicUnkonwnSec);
    int e = -d * kMagicUnkonwnSec;
    e = e / 4 + c;
    int m = (5 * e + 2) / kDaysFromYear;

    tm.tm_mday = -(kDaysFromYear * m + 2) / 5 + e + 1;
    tm.tm_mon = (-m / 10) * 12 + m + 2;
    tm.tm_year = b * 100 + d - 6700 + (m / 10);

    std::stringstream ss;
    ss << std::put_time(&tm, fmt); //#include <iomanip>
    return ss.str();
}

/* Get level string */
static std::string LogLevelStr(LogLevel level){
    switch (level) {
        case LogLevel::DEBUG:
            return "debug";
        case LogLevel::INFO:
            return "info";
        case LogLevel::ERROR:
            return "error";
        case LogLevel::FATAL:
            return "fatal";
    }
    return "debug";
}

/* Set buffer for log (console / file) */
static void SetLogBuf(std::streambuf* buf) {
    logOut.rdbuf(buf);
}

static void ReplaceString(std::string &str,
                          std::string rstr,
                          std::string newstr)
{
    auto pos = str.find(rstr);
    if (pos == std::string::npos) return;
    str.replace(pos, rstr.size(), newstr);
}

bool LogInit(LogType type, std::string format, std::string para)
{
    logFormat = format;

    switch (type) {
        case LogType::Console:
            SetLogBuf(std::cout.rdbuf()); break;
        case LogType::File:
            logFile = std::ofstream(para, std::ios::app);
            if (!logFile.is_open()) return false;
            SetLogBuf(logFile.rdbuf());
    }
    return true;
}

void LogWrite(LogLevel level, std::string content, std::string file, int line)
{
    std::string levelstr = LogLevelStr(level);

    if (logFormat.empty()) {
        logOut << GetNow() << " " << levelstr << " " << content << " "
               << file     << ":" << line     <<  std::endl;
    } else {
        std::string logStr = logFormat;
        ReplaceString(logStr, "{time}",    GetNow());
        ReplaceString(logStr, "{level}",   levelstr);
        ReplaceString(logStr, "{content}", content);
        ReplaceString(logStr, "{file}",    file);
        ReplaceString(logStr, "{line}",    std::to_string(line));
        logOut << logStr << std::endl;
    }
}

