#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N, W;
  cin >> N >> W;
  vector<int> a(N);

  for (int i = 0; i < N; ++i)
    cin >> a.at(i);

  // 線形探索
  bool exist = false;
  // bit は 2^Nの部分集合全体を動く
  for (int bit = 0; bit < (1 << N); ++bit)
  {
    int sum = 0;
    for (int i = 0; i < N; ++i)
    {
      if (bit & (1 << i))
      {
        sum += a.at(i);
      }
    }

    if (sum == W)
    {
      exist = true;
    }
  }

  if (exit)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}