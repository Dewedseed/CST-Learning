#include <iostream>
#include "base.h"
using namespace std;

int main()
{
  ++gcount;
  cout << "global variable " << gcount << endl;
  TestFunc(1, 2);
  TestC();
  TestC1();
  TestC2();
}
