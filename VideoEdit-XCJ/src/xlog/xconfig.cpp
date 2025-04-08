#include "xconfig.h"
#include <fstream>
#include <string>
using namespace std;

const std::string& XConfig::Get(const std::string& key)
{
    static string resEmpty = "";
    auto c = conf_.find(key);
    if (c == conf_.end()) return resEmpty;
    return c->second;
}

bool XConfig::Read(const std::string &file)
{
    ifstream ifs(file);
    if(!ifs.is_open()) return false;
    string line;
    string key, val;
    for (;;) {
        getline(ifs, line);
        if (!line.empty()) {
            // rm \n
            line.erase(line.find_last_not_of("\n\r") + 1);
            // log_file=log.txt
            auto p = line.find('=');
            if (p <= 0) continue;
            key = line.substr(0, p);
            val = line.substr(p+1);
            conf_[key] = val;
        }
        if (!ifs.good()) break;
    }
    return true;
}
