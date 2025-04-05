#include <iostream>
using namespace std;

/*
test pointer
*/
void TestParaPtr(const int* x, const int* y)
{
  cout << "TestParaPtr" << *x << " " << *y << endl;
  cout << x << " " << y << endl;
}

/*
test Reference
*/
void TestParaRef(const int& x, const int& y)
{
  cout << "TestParaRef" << x << " " << y << endl;
  cout << &x << " " << &y << endl;
}

/* Get pointer */
void GetParaPtr(int* x, int* y)
{
  *x = 199;
  *y = 200;
}

/* Get reference */
void GetParaRef(int& x, int& y)
{
  x = 299;
  y = 300;
}

/* Return static local variable */
int* ReturnLocalStaticPtr()
{
  static int pos{ 0 };
  cout << "ReturnLocalStaticPtr pos:" << pos << endl;
  return &pos;
}

/* Return static local variable */
int& ReturnLocalStaticRef()
{
  static int pos{ 0 };
  cout << "ReturnLocalStaticRef pos:" << pos << endl;
  return pos;
}

int main()
{
  int x{10};
  cout << "--------x--------" << endl; // 10
  cout << x << endl; // 10
  cout << &x << endl; // 1001

  int* p{ &x };
  *p = 11;
  cout << "--------p--------" << endl; // 10
  cout << *p << endl; // 11
  cout << p << endl; // 1001
  cout << &p << endl; // 1009


  int& ref{ x };
  cout << "-------ref-------" << endl; // 10
  cout << ref << endl; // 11
  cout << &ref << endl; // 1001

  int xx {99};
  int yy {99};

  TestParaPtr(&xx, &yy);
  TestParaRef(xx, yy);

  GetParaPtr(&xx, &yy);
  cout << xx << " " << yy << endl;

  GetParaRef(xx, yy);
  cout << xx << " " << yy << endl;

  auto resPtr = ReturnLocalStaticPtr();
  (*resPtr) += 10;
  ReturnLocalStaticPtr();

  auto &resRef = ReturnLocalStaticRef();
  resRef += 10;
  ReturnLocalStaticRef();

  return 0;
}
