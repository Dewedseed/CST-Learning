#include "logger.h"

#include <iostream>

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
        default:
            break;
    }
    return "debug";
}


/// Format and write log
/// @para level log level
/// @para log   log content
/// @para file  source file path
/// @para line  code line in source file
void Logger::Write (
    LogLevel level,
    const std::string &log,
    const std::string &file,
    int line
){
    // fut_ = std::async([=]{
        // std::lock_guard<std::mutex> lock(mux_);
        // if (!output_ || !format_) return;
        if (!output_ || !format_) return;
        if (level < log_level_) return;
        // get loglevel string
        std::string levelstr = LogLevelStr(level);
        // format log
        auto str = format_->Format(levelstr, log, file, line);
        // output log
        output_->Output(str);
        return;
    // });
}

