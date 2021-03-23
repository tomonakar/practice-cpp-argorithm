#include <iostream>
#include <vector>
using namespace std;
const int INF = 2000000000;

// 線形探索 ペアの和の最小値を求める(K以上の範囲)
int main()
{
  int N, K;
  cin >> N >> K;
  vector<int> a(N), b(N);
  for (int i = 0; i < N; ++i)
  {
    cin >> a.at(i);
  }
  for (int i = 0; i < K; ++i)
  {
    cin >> b.at(i);
  }

  // 線形探索
  int min_value = INF;
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < K; ++j)
    {
      int value = a.at(i) + b.at(j);
      if (value < K)
      {
        continue;
      }

      if (value < min_value)
      {
        min_value = value;
      }
    }
  }
  cout << min_value << endl;
}