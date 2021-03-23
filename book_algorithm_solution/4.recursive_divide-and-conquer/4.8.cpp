#include <iostream>
#include <vector>
using namespace std;

// fibo(N) の答えをメモ化する配列(一旦グローバル変数にするが本来はよく無い)
vector<long long> memo;

long long fibo(int N)
{
  if (N == 0)
    return 0;
  if (N == 1)
    return 1;

  // メモをチェックし、存在すればメモの値を返す
  if (memo.at(N) != -1)
    return memo.at(N);

  // メモ化しながら、再起呼び出し
  return memo.at(N) = fibo(N - 1) + fibo(N - 2);
}

int main()
{
  // メモ用配列を-1で初期化
  memo.assign(50, -1);

  // fibo 49で呼び出す
  fibo(49);
  for (int N = 2; N < 50; ++N)
  {
    cout << N << "　項目: " << memo.at(N) << endl;
  }
}
