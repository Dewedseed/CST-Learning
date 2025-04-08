#pragma once

#include "xlog.h"

#include <future>
#include <map>
#include <string>
#include <functional>
#include <vector>

class XLOG_API UserInput
{
public:
    /// Start console and get input
    void Start(std::function<void(std::vector<std::string>)> init
                             = [](std::vector<std::string>){});

    /// stop console
    void Stop() {is_exit_ = true;}

    /// Register
    UserInput& Reg(std::string key, std::function<void(const std::string&)> func);

    /// Register task function
    UserInput& RegTask(std::string key, std::function<void()> func);

private:
    bool is_exit_{ false };

    // keyword map (key, func)
    // key: -s -d
    std::map<std::string, std::function<void(const std::string&)>> key_funcs_;

    // initial function
    std::function<void()> init_func_ = []{};

    // task execute function
    std::map<std::string, std::function<void()>> task_func_;
};
