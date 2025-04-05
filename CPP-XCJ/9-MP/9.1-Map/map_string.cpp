#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

int main()
{
    map<int, string> mis {
        {1, "value 1"},
        {4, "value 4"},
        {5, "value 5"},
    };

    for (auto &v : mis) {
        cout << v.second << endl;
    }

    mis[7] = "value 7";

    cout << mis[5] << ":" << mis.size() << endl;
    cout << mis[6] << ":" << mis.size() << endl;

    mis.insert(make_pair(8, "value 8"));

    mis.erase(7);

    auto f1 = mis.find(4);
    mis.erase(f1);

    auto itr = mis.find(11);
    if (itr != mis.end()) {
        cout << itr->first << ":" << itr->second << endl;
    }

    for (auto v = mis.begin(); v!= mis.end(); ++v) {
        cout << v->first << ":" << v->second << endl;
    }

    mis.clear();
};
