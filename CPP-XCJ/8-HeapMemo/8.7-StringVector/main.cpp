#include "string_vector.h"

#include <iostream>
using namespace std;

int main()
{
    StringVector vec(2);

    vec.Push("test 001");
    vec.Push("test 002");

    cout << vec.Size() << ":" << vec.Capacity() << endl;

    vec.Push("test 003");

    cout << vec.Size() << ":" << vec.Capacity() << endl;

    vec.Push("test 004");
    vec.Push("test 005");

    cout << vec.Size() << ":" << vec.Capacity() << endl;

    for (int i = 0; i < vec.Size(); ++i) {
        cout << vec[i] << endl;
    }
}
