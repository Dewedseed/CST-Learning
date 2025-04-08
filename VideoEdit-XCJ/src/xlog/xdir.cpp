#include "xdir.h"

#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool XDir::IsDir(const std::string &path) {
    return filesystem::is_directory(path);
}

bool XDir::Create(const std::string &path) {
    return filesystem::create_directories(path);
}


std::vector<XFile> XDir::GetFiles(std::string path)
{
    std::vector<XFile> files;

    // path
    auto itr = filesystem::recursive_directory_iterator(path);
    for (auto & p : itr) {
        if(p.is_directory()) continue;
        if(!p.is_regular_file()) continue;
        files.push_back({
            p.path().filename().string(),
            p.path().string(),
            p.path().extension().string(),
        });
    }

    return files;
}

