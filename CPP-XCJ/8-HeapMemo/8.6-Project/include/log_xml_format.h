#pragma once
#include "log_format.h"

class LogXMLFormat:public LogFormat
{
public:
    ///
    /// Format log to string
    /// @para level log level
    /// @para log   log content
    /// @para file  source file path
    /// @para line  code line in source file
    ///
    std::string Format(
        const std::string &level,
        const std::string &log,
        const std::string &file,
        int line
    ) override;
};

