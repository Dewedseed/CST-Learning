#pragma once
#include "log_output.h"

class LogConsoleOutput:public LogOutput
{
public:
    /// output log
    /// @para log log content after format
    void Output(const std::string &log) override;
};
