#include <cstddef>
#include <iostream>
using namespace std;

int* TestBaseArr(int datas[], int size)
{
  cout << "TestBaseArr size = " << size << endl;
  return datas;
}

using ArrType = int[10];
ArrType& TestBaseArrRef(int (&datas)[10])
{
  cout << "TestBaseArrRef size =" << sizeof(datas) << endl;
  return datas;
}

int main()
{
  int datas[10] = {1, 2, 3, 4, 5};

  cout << sizeof datas << endl;

  TestBaseArr(datas, sizeof(datas) / sizeof(int));

  TestBaseArrRef(datas);
}
