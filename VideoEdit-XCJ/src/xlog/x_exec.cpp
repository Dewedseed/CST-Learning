#include "x_exec.h"

#include <iostream>
#include <cstdio>
#include <cstdio>

using namespace std;

#ifdef _WIN32
#else
#define _popen popen
#define _pclose pclose
#endif

/// Executable external process
bool XExec::Start(const char* cmd,
                  std::function<void(const std::string&)> func
){
    // redirect error output to standard output
    string tmp = cmd;
    tmp += " 2>&1"; // error => standard

    cout << tmp << endl;

    // get console pip
    auto fp = _popen(tmp.c_str(), "r");
    if (!fp) return false;

    running_ = true;

    // get command exe result
    fut_ = async([fp, this, func]{
        string tmp;
        char c = 0;
        while (c = fgetc(fp)) {
            if (c == EOF) break;
            if (c == '\n' || c == '\r') {
                if (tmp.empty()) continue;
                {
                    if (func) {
                        func(tmp);
                    } else {
                        lock_guard<mutex> lock(mux_);
                        outs_.push(tmp);
                    }
                }
                tmp = "";
                continue;
            }
            tmp += c;
        }
        _pclose(fp);
        running_ = false;
        return true;
    });

    return true;
}


bool XExec::Runing() {
    return running_;
}


bool XExec::GetOutput(std::string &out) {
    lock_guard<mutex> lock(mux_);
    if (outs_.empty()) return false;
    out = move(outs_.front());
    outs_.pop();
    return true;
}
