#pragma once
#include <string>

/// output interface
class LogOutput
{
public:
    virtual ~LogOutput() {}

    /// output log
    /// @para log log content after format
    virtual void Output(const std::string &log) = 0;
};
