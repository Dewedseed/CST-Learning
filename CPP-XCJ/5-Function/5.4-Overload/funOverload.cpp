#include <cstddef>
#include <iostream>
using namespace std;

/* Declear Function */
void TestOverload(int x,
  int y = 200,
  int z = 300);

/* Define Function */
void TestOverload(int x, int y, int z)
{
  cout << "TestOverload "
       << x << ", "
       << y << ", "
       << z << endl;
}

void TestOverload()
{
  cout << __FUNCTION__ << endl;
}

void TestNull(int)
{
  cout << __PRETTY_FUNCTION__ << endl;
}

void TestNull(int *)
{
  cout << __PRETTY_FUNCTION__ << endl;
}

int main()
{
  TestOverload(100);
  TestOverload(101, 210);
  TestOverload(102, 220, 320);
  TestOverload();

  TestNull(123);
  // TestNull(NULL);
  TestNull(nullptr);
}
