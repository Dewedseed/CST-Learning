#include <fstream>
#include <ios>
#include <string>
#include <iostream>
using namespace std;

void TestWriteTxt()
{
    string testfile = "testfile.txt";

    fstream wfs(testfile, ios::out|ios::binary);
    // wfs.open(testfile, ios::out|ios::binary)；
    wfs << "1234567890\n";
    wfs.close();

    ofstream ofs;
    ofs.open(testfile, ios::app|ios::binary);
    ofs << "ABCDEFG\n" << flush;
    ofs.write("1234", 4);
    ofs.close();
}

int TestReadTxt()
{
    string testfile = "testfile.txt";

    fstream rfs(testfile, ios::in|ios::binary);
    if (!rfs.is_open()) {
        cerr << "Open file " << testfile << " failed!" << endl;
        return -1;
    }

    char buf[4090]{ 0 };
    rfs.read(buf, sizeof(buf)-1);
    cout << rfs.gcount() << endl;
    cout << "-----------------" << endl;
    cout << buf << endl;
    cout << "-----------------" << endl;
    rfs.close();

    ifstream ifs(testfile, ios::binary|ios::ate);
    cout << testfile << "  filesize = " << ifs.tellg() << endl;
    ifs.close();

    return 0;
}

void TestReadTxtRealtime()
{
    string testfile = "testfile.txt";
    ifstream ifs(testfile, ios::binary|ios::ate);

    string line;
    for (;;) {
        getline(ifs, line);
        if (!line.empty())
            cout << "Line: " << line << endl;
        ifs.clear();
    }

    ifs.close();
}

int main()
{
    TestWriteTxt();
    TestReadTxt();
    TestReadTxtRealtime();
}


