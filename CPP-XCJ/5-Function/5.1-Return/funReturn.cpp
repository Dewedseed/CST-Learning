#include <iostream>
using namespace std;

/* 返回值 */
bool View(int index)
{
  cout << "call View(" << index << ")" << endl;
  return true;
}

void TestVoid(void)
{
  return;
}

/* 复制值 */
void SetSize(int w, int h)
{
  w += 1;
  cout << w << ":" << h << endl;
  cout << (long long) &w << ":"
       << (long long) &h << endl;
}

int main()
{
  auto re = View(-1024);
  cout << re << endl;

  int w = 1920, h = 1080;
  cout << (long long) &w << ":"
       << (long long) &h << endl;
  SetSize(w, h);
  cout << "w = " << w
       << " h = " << h << endl;

  return 0;
}
