#pragma once
#include "xlog.h"

#include <string>
#include <vector>

struct XLOG_API XFile
{
    std::string name;
    std::string path;
    std::string ext;
};

// Batch processing of directories
class XLOG_API XDir
{
public:
    /// Get all files in folder
    /// @para path folder path
    /// @return files name
    std::vector<XFile> GetFiles(std::string path);

    static bool IsDir(const std::string& path);

    static bool Create(const std::string& path);
};
