#include <iostream>
using namespace std;

// global variable
int gcount = 0;

// static global variable, only visiable in current file
static int scount = 0;

// function
int TestVar(int x, int y)
{
  int tmp = x + y; // local variable
  static int count = 0; // static local variable

  ++gcount;
  ++scount;
  ++count;

  cout << "gcount = " << gcount << endl;
  cout << "scount = " << scount << endl;
  cout << "count = "  << count  << endl;

  return tmp;
}

// executable
int main()
{
  TestVar(100, 200);
  TestVar(200, 300);
  auto re = TestVar(300, 400);

  cout << "re = " << re << endl;

  return 0;
}
