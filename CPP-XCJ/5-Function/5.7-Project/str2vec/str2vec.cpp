#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

/*
Convert string to vector
    char *  => vector<unsigned char>
    char [] => vector<unsigned char>
    string  => vector<unsigned char>
    vector<unsigned char> =>  string
*/
int main()
{
    const char* cstr{ "test const char* to vector" };
    int size = strlen(cstr);
    // memory position: begin, end (\0)
    vector<unsigned char> data(cstr, cstr + size + 1);
    cout << data.data() << endl;
    cout << size << ":" << data.size() << endl;

    char astr[]{ "test array to vector" };
    data.clear();
    // data.assign(astr, &astr[sizeof(astr)]);
    data.assign(astr, astr + sizeof(astr));
    cout << data.data() << endl;
    cout << sizeof(astr) << ":" << data.size() << endl;

    string str{ "test string to vector" };
    data.clear();
    // data.assign(str.begin(), str.end());
    // data.push_back('\0');
    data.assign(str.data(), str.data() + str.size() + 1);
    cout << data.data() << endl;
    cout << str.length() << ":" << data.size() << endl;

    string outstr(data.begin(), data.end() - 1);
    cout << outstr << endl;
    cout << data.size() << ":" << outstr.length() << endl;
}
