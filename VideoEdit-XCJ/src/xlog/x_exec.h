#pragma once

#include "xlog.h"

#include <mutex>
#include <string>
#include <queue>
#include <future>
#include <mutex>
#include <functional>

class XLOG_API XExec
{
public:
    /// Executable external process
    /// @para cmd console command
    /// @para func console callback function, not save to buff queue if setted
    /// @return whether open pip
    bool Start(const char* cmd,
               std::function<void(const std::string&)> func = nullptr);

    /// task stat
    bool Runing();

    /// Get output string
    /// @para out output string
    /// @return whether get output
    bool GetOutput(std::string& out);

    /// wait thread exit
    bool Wait() {return fut_.get();}

private:
    bool running_{ false };

    // buffer queue
    std::queue<std::string> outs_;

    // task thread
    std::future<bool> fut_;
    std::mutex mux_;
};
