#include <iostream>
#include <vector>
using namespace std;

template <class T>
void chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
  }
}

const long long INF = 1LL << 60;

// 入力データとメモ用のDPテーブル
int N;
vector<long long> h;
vector<long long> dp;

long long rec(int i)
{

  // DPが更新されてたらそのまま値を返す
  if (dp[i] < INF)
    return dp[i];

  // ベースケース
  if (i == 0)
    return 0;

  // 答えを表す変数をINFで初期化
  long long res = INF;

  // 足場 i - 1 からきた場合
  chmin(res, rec(i - 1) + abs(h[i] - h[i - 1]));

  // 足場 i - 2 から来た場合
  if (i > 1)
  {
    chmin(res, rec(i - 2) + abs(h[i] - h[i - 2]));
  }

  // 結果をメモ化しながら返す
  return dp[i] = res;
}

int main()
{
  cin >> N;
  h.resize(N);
  for (int i = 0; i < N; ++i)
    cin >> h[i];

  dp.assign(N, INF);

  cout << rec(N - 1) << endl;
}