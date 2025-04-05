#include <ios>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void TestSStream()
{
    stringstream ss;

    ss << "test stringstream:" << 100 << true;

    ss << boolalpha;
    ss << hex;
    ss << "\n" << false << 100 << endl;

    ss.str("");

    cout << ss.str() << endl;
}

void TestIssFormat()
{
    string data = "Test 1 2 3";
    stringstream ss(data);

    string tmp;
    ss >> tmp; cout << tmp << ",";
    ss >> tmp; cout << tmp << ",";
    ss >> tmp; cout << tmp << endl;

    data = "test1 test2 test2\ntest4 test5 test6\ntest6 test2 test1";
    ss.str(data);

    for (;;) {
        getline(ss, tmp);
        cout << "line " << tmp << endl;

        if (ss.eof()) break;
    }
}


int main()
{
    TestSStream();
    TestIssFormat();
}
