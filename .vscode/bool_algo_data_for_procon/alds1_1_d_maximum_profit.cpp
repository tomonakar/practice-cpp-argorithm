#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  // 入力
  int N;
  cin >> N;
  vector<int> t(N);
  for (int i = 0; i < N; ++i) {
    cin >> t[i];
  }

  int maxv = -10000000;
  int minv = t[0];

  for (int i = 0; i < N; i++) {
    maxv = max(maxv, t[i] - minv);
    minv = min(minv, t[i]);
  }

  cout << maxv << endl;
}