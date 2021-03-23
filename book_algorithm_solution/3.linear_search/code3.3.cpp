#include <iostream>
#include <vector>
using namespace std;
const int INF = 2000000000; // 十分大きな値を宣言

// 線形探索（最小値を見つける）
int main()
{
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; ++i)
  {
    cin >> a.at(i);
  }

  // 線形探索
  int min_value = INF;
  for (int i = 0; i < N; ++i)
  {
    if (a.at(i) < min_value)
    {
      min_value = a.at(i);
    }
  }

  cout << min_value << endl;
}