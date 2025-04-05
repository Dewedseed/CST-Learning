#include <iostream>
#include <vector>
#include "base16.h"
using namespace std;

int main()
{
    string teststr{ "test base16 data" };
    vector<unsigned char> data(
        teststr.data(),
        teststr.data() + teststr.size()
        );

    cout << "source: " << teststr << endl;

    auto base16str = Base16Encode(data);
    cout << "base16 encode: " << base16str << endl;

    auto resdata = Base16Decode(base16str);
    // cout << "base16 decode: " << resdata.data() << endl;
    cout << "base16 decode: ";
    for (auto ch : resdata)
        cout << ch;
    cout << endl;
}
