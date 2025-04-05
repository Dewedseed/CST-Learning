#include <iostream>
#include <vector>
using namespace std;

vector<int> TestVec(vector<int> vdatas)
{
  cout << "------- Begin -------" << endl;
  cout << "function vdatas: " << vdatas.data() << endl;
  cout << vdatas.size() << endl;
  for (auto& d : vdatas)
    cout << d << " ";
  cout << endl;
  cout << "-------- End --------" << endl;
  return vdatas;
}

vector<int> TestVecRef(vector<int>& vdatas)
{
  cout << "------- Begin -------" << endl;
  cout << "function vdatas: " << vdatas.data() << endl;
  cout << vdatas.size() << endl;
  for (auto& d : vdatas)
    cout << d << " ";
  cout << endl;
  cout << "-------- End --------" << endl;
  return vdatas;
}

int main()
{
  vector<int> vdatas{11, 22, 33, 4, 5};

  cout << "main vdatas: " << vdatas.data() << endl;
  auto rdatas = TestVec(vdatas);
  cout << "main rdatas: " << rdatas.data() << endl;

  cout << "main vdatas: " << vdatas.data() << endl;
  auto mdatas = TestVec(move(vdatas));
  cout << "main rdatas: " << mdatas.data() << endl;
  cout << "main vdatas: " << vdatas.data() << endl;

  cout << "========= Ref =========" << endl;

  cout << "main mdatas: " << mdatas.data() << endl;
  auto refDatas = TestVecRef(mdatas);
  cout << "main refDatas: " << refDatas.data() << endl;
}
