#include "base.h"

int gcount = 0;

int TestFunc(int, int x, int y)
{
  return 0;
}

extern "C" void TestC() {}

extern "C"
{
  void TestC1() {};
  void TestC2() {};
}
