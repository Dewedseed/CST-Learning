#pragma once

#include "x_exec.h"
#include "xtask.h"

// xtask module using ffmpeg tool
class FFTask:public XTask
{
public:
    /// start process task
    /// @para Data task configure parameter
    /// @return execute state
    bool Start(const Data& para) override;

    /// Get task progress
    /// @return 0 ~ 100
    int Progress() override {return progress_;};

    /// Get video total time(s)
    int TotalSec() override {return total_sec_;}

    /// if task is running
    bool Running() override {return exec_.Runing();};

    /// clear buffer
    void Clear() override {
        total_sec_ = 0;
        progress_ = 0;
    }

private:
    int total_sec_{ 0 }; // video total time
    int progress_ { 0 }; // progress

    XExec exec_;
};
