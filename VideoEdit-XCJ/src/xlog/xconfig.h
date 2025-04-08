#pragma once

#include <string>
#include <map>

class XConfig
{
public:
    /// Read configure file
    /// @return read state
    bool Read(const std::string& file);

    const std::string& Get(const std::string& key);

private:
    std::map<std::string, std::string> conf_;
};
