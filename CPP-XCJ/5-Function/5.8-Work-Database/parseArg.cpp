#include "parseArg.h"

/*
parse argument
- format: keyword [key] [val]
- keyword insert, get, delete, print, exit
*/
std::vector<std::string> ParseArg(std::string arg) {
    std::vector<std::string> argVec;
    // parse argument
    arg += ' ';
    std::string tmp;
    for (auto ch : arg) {
        if (ch == ' ' || ch == '\r' || ch == '\t' || ch == '\n') {
            argVec.push_back(tmp);
            tmp.clear();
        } else {
            tmp += ch;
        }
    }
    // check
    if ((argVec[0] == "insert" && argVec.size() != 3) ||
        (argVec[0] == "get"    && argVec.size() != 2) ||
        (argVec[0] == "delete" && argVec.size() != 2) ||
        (argVec[0] == "print"  && argVec.size() != 1) ||
        (argVec[0] == "exit"   && argVec.size() != 1)) {
        argVec.clear();
        argVec.push_back("exit");
        argVec.push_back("exit");
    }
    return argVec;
}
