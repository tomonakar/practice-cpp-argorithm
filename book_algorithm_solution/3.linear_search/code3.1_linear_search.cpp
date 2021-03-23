#include <iostream>
#include <vector>
using namespace std;

// 線形探索 フラグを用意して任意の値が存在するかチェック
int main()
{
  int N, v;
  cin >> N >> v;
  vector<int> a(N);
  for (int i = 0; i < N; ++i)
  {
    cin >> a.at(i);
  }

  // 線形探索
  bool exist = false;
  for (int i = 0; i < N; ++i)
  {
    if (a.at(i) == v)
    {
      exist = true;
    }
  }

  if (exist)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}