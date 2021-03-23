#include <iostream>
#include <vector>
using namespace std;

// 線形探索 任意の値の添字を返す
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
  const int NOT_FOUND = -1;
  int found_index = NOT_FOUND;
  for (int i = 0; i < N; ++i)
  {
    if (a.at(i) == v)
    {
      found_index = i;
      break;
    }
  }

  cout << found_index << endl;
}