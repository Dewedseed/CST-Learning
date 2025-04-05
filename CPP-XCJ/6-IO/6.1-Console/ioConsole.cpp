#include <cstring>
#include <ios>
#include <iostream>
#include <string>
using namespace std;

void TestCoutFormat()
{
    // cout-ostream
    {
        cout << "Hello World!" << endl;

        // integer
        cout << 100 << endl;
        cout << oct;
        cout << 100 << endl;
        cout << hex << 100 << endl;
        cout << dec;
        cout << 100 << endl;

        // bool
        cout << true << ":" << false << endl;
        cout << boolalpha;
        cout << true << ":" << false << endl;
    }

    // out of stack
    cout << true << ":" << false << endl;
    cout << noboolalpha;
    cout << true << ":" << false << endl;

    cout << flush;
}

void TestCoutNoFormat()
{
    cout.put('A').put('B');
    cout.put('C');
    cout.put(68);

    cout.write("123", 3);

    string str = "Testing";
    cout.write(str.c_str(), str.size());

    cout << endl;
}

void TestCerr()
{
    cerr << "error out" << endl;
}

void TestCinFormat()
{
    while (true) {
        cout << ">>";
        char buf[1024]{ 0 };
        cin.getline(buf, sizeof(cin) - 1);
        cout << buf << endl;

        if (strstr(buf, "exit"))
            break;

        cout << "$$";
        string line;
        getline(cin, line);
        cout << line << endl;

        if (strstr(buf, "exit"))
            break;
    }

    while (true) {
        char c = cin.get();
        cout << c << flush;
    }
}

void TestCinError()
{
    for (; ; ) {
        cout << "Input number: " << flush;
        int x{ 0 };
        cin >> x;

        // if (cin.rdstate() == std::ios_base::failbit) break;
        if (cin.fail()) {
            string line;
            cin.clear();
            getline(cin, line);
            cout << "cin fail: " << line << endl;
            continue;
        }

        cout << "x = " << x << endl;
    }
}

int main()
{
    // TestCoutFormat();
    // TestCoutNoFormat();
    // TestCerr();
    // TestCinFormat();
    TestCinError();
}
