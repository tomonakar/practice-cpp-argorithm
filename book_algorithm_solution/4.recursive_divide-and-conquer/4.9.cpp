#include <iostream>
#include <vector>
using namespace std;

// 部分和問題を再帰的に解く
// N個の正の整数(a0, a1...aN-1)を何個か選んで、正の整数Wが作れるか。
bool func(int i, int w, const vector<int> &a)
{
  // ベースケース
  if (i == 0)
  {
    if (w == 0)
      return true;
    else
      return false;
  }

  // a[i - 1] を選ばない場合
  if (func(i - 1, w, a))
    return true;

  // a[i -1] を選ぶ場合
  if (func(i - 1, w - a[i - 1], a))
  {
    cout << "選択： " << a[i - 1] << endl;
    return true;
  }

  // どちらもfalseの場合
  return false;
}

int main()
{
  // 入力
  int N, W;
  cin >> N >> W;
  vector<int> a(N);
  for (int i = 0; i < N; ++i)
    cin >> a[i];

  // 再帰的に解く
  if (func(N, W, a))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}