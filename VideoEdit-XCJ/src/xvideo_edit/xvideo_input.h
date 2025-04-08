#pragma once

#include "xtask.h"

#include <memory>

class XVideoInput
{
public:
    /// receive user input and call task
    void Start(std::unique_ptr<XTask> task);

private:
    void RunTask(XTask &task, const XTask::Data &data);
};
