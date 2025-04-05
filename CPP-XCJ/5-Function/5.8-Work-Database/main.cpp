#include <iostream>
#include <string>
#include <vector>
#include "database.h"
#include "parseArg.h"
using namespace std;

int main()
{
    while (true) {
        // input
        cout << ">>" << flush;
        string cmd;
        getline(cin, cmd);
        // parse input command
        vector<string> argVec = ParseArg(cmd);
        // database operation
        if (argVec[0] == "insert") {
            InsertData(argVec[1], argVec[2]);
        } else if (argVec[0] == "get") {
            string val = GetData(argVec[1]);
            cout << val << endl;
        } else if (argVec[0] == "delete") {
            DeleteData(argVec[1]);
        } else if (argVec[0] == "print") {
            printData();
        } else {
            if (argVec.size() == 1) {
                cout << "EXIT" << endl;
                break;
            }
            cout << " ERROR: " << cmd << endl;
        }
    }
}
