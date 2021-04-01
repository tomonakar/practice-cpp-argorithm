#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1LL << 60;

template <class T>
void chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
  }
}

long long rec(int i)
{
  if (i == 0)
  {
    return 0;
  }

  long long res = INF;
  chmin(res, rec(i - 1) + abs(dp[i] - dp[i - 1]));

  if (i > 1)
  {
    chmin(res, rec(i - 2) + rec(i - 2) + abs(dp[i] - dp[i - 2]));
  }
  return res;
}

int main()
{

  int N;
  cin >> N;
  vector<long long> dp(N, INF);
  for (i = 0; i < N; ++i)
  {
    cin >> dp[i];
  }

  dp[0] = 0;

  cout << rec(N - 1) << endl;
}