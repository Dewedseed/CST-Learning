/*
Requirement
(1) insert data
(2) find data
(3) delete data
*/
#include <string>
#include <vector>
#include <iostream>

/*
insert (key, val) to database
@para key data key
@para val data value
@return insert state
*/
bool InsertData(std::string key, std::string val);

/*
get value from database by key
@para key data key
@return data value
*/
std::string GetData(std::string key);

/*
delete value from database by key
@para key data key
@return delete state
*/
bool DeleteData(std::string key);

/*
print data key:value
*/
void printData();
