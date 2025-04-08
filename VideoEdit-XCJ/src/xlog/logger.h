#pragma once

#include "xlog.h"
#include "log_format.h"
#include "log_output.h"

#include <string>
#include <memory>
#include <future>
#include <mutex>

enum class LogLevel {
    DEBUG,
    INFO,
    ERROR,
    FATAL
};

/// Combination class
class XLOG_API Logger
{
public:
    ~Logger(){
        // delete output_; output_ = nullptr;
        // delete format_; format_ = nullptr;
    }

    void SetOutput(std::unique_ptr<LogOutput> o) {output_ = move(o);}
    void SetFormat(std::unique_ptr<LogFormat> f) {format_ = move(f);}
    void SetLevel(LogLevel level) {log_level_ = level;}

    /// Format and write log
    /// @para level log level
    /// @para log   log content
    /// @para file  source file path
    /// @para line  code line in source file
    void Write (
        LogLevel level,
        const std::string &log,
        const std::string &file,
        int line
    );

private:
    // LogOutput *output_{nullptr};
    // LogFormat *format_{nullptr};

    std::unique_ptr<LogOutput> output_;
    std::unique_ptr<LogFormat> format_;

    LogLevel log_level_{ LogLevel::DEBUG };

    // thread for output
    // std::future<bool> fut_;
    // std::mutex mux_;
};
