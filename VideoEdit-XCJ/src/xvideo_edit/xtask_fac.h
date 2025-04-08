#pragma once

#include "xtask.h"

#include <memory>

// create xtack object
class XTaskFactory
{
public:
    static std::unique_ptr<XTask> Create(int type = 0);
private:
};
