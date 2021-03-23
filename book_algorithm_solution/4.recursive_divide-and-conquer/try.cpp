#include <iostream>
#include <vector>
using namespace std;

int fibo(int N)
{
  if (N == 0)
    return 0;
  if (N == 1)
    return 1;

  return fibo(N - 1) + fibo(N - 2);
}

int main()
{
  vector<long long> F(50);
  F.at(0) = 0, F.at(1) = 1;

  for (int N = 2; N < 50; ++N)
  {
    F.at(N) = F.at(N - 1) + F.at(N - 2);
    cout << F.at(N) << endl;
  }
}