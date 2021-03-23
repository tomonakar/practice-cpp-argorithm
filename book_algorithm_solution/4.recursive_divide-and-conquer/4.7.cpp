#include <iostream>
#include <vector>
using namespace std;

// フィボナッチ数列をfor文による反復で求める
int main()
{
  // long long型 ＠see: https://cpprefjp.github.io/lang/cpp11/long_long_type.html
  vector<long long> F(50);
  F.at(0) = 0, F.at(1) = 1;
  for (int N = 2; N < 50; ++N)
  {
    F.at(N) = F.at(N - 1) + F.at(N - 2);
    cout << N << "項目: " << F.at(N) << endl;
  }
}