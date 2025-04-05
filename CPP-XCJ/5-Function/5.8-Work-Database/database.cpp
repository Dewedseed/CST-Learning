#include "database.h"
#include <iostream>
#include <ostream>
#include <vector>

// number of data
static int ndata{ 0 };
// vector save data key
static std::vector<std::string> keyVec;
// vector save data value
static std::vector<std::string> valVec;

/*
insert (key, val) to database
@para key data key
@para val data value
@return insert state
*/
bool InsertData(std::string key, std::string val) {
    keyVec.emplace_back(key);
    valVec.emplace_back(val);
    ++ndata;

    std::cout << "Add data success" << std::endl;
    return true;
}

/*
get value from database by key
@para key data key
@return data value
*/
std::string GetData(std::string key) {
    for (int i = 0; i < ndata; ++i) {
        if (keyVec[i] == key) return valVec[i];
    }
    return "";
}

/*
delete value from database by key
@para key data key
@return delete state
*/
bool DeleteData(std::string key) {
    int fIdx = ndata;
    for (int i = 0; i < ndata; ++i) {
        if (keyVec[i] == key) {
            fIdx = i;
            break;
        }
    }
    // delete data
    if (fIdx != ndata) {
        --ndata;
        swap(keyVec[fIdx], keyVec[ndata]);
        swap(valVec[fIdx], valVec[ndata]);
        keyVec.pop_back();
        valVec.pop_back();
        return true;
    }
    return false;
}


/*
print data key:value
*/
void printData() {
    std::cout << "--------- Print Database --------" << std::endl;
    for (int i = 0; i < ndata; ++i) {
        std::cout << keyVec[i] << ":" << valVec[i] << std::endl;
    }
    std::cout << "---------------------------------" << std::endl;
    std::cout << std::endl;
}
