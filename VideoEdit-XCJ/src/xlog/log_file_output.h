#pragma once
#include "log_output.h"

#include <fstream>
#include <string>

class LogFileOutput:public LogOutput
{
public:
    /// output log
    /// @para log log content after format
    void Output(const std::string &log) override;

    /// Open log file
    /// @para file file path
    /// @return open success or fail
    bool Open(const std::string& file);

private:
    std::ofstream ofs_;
};
