#include "user_input.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <sstream>
#include <functional>

using namespace std;

static vector<string> Split(const string& s) {
    vector<string> vec;
    string tmp;
    istringstream is(s);
    while (getline(is, tmp, ' ')) {
        if (tmp.empty()) continue;
        vec.push_back(tmp);
    }
    return vec;
}

UserInput& UserInput::Reg(std::string key,
                    std::function<void (const std::string &)> func)
{
    key_funcs_[key] = func;
    return *this;
}

UserInput& UserInput::RegTask(std::string key, std::function<void ()> func)
{
    task_func_[key] = func;
    return *this;
}

void UserInput::Start(std::function<void(std::vector<std::string>)> init)
{
    // get user input
    while (!is_exit_) {
        string input;

        // get input string
        cout << "\n>> " << flush;
        getline(cin, input);
        if (input == "exit") break;

        // split input string
        auto vec = Split(input);
        if (vec.empty()) continue;

        // initial task
        //   cv -s test.mp4 -d test.avi
        string type = vec[0];
        init(vec);

        for (int i = 1; i < vec.size(); ++i) {
            auto &k = vec[i];
            auto fitr = key_funcs_.find(k);
            if (fitr != key_funcs_.end()) {
                if (vec.size() - 1 > i) {
                    auto &v = vec[i + 1];
                    if (key_funcs_.find(v) == key_funcs_.end()) {
                        fitr->second(v);
                        ++i;
                        continue;
                    }
                }
                fitr->second("");
            }
        }

        // execute task
        auto task = task_func_.find(type);
        if (task == task_func_.end()) {
            cerr << type << " not support!" << endl;
        } else {
            task->second();
        }
    }
}
