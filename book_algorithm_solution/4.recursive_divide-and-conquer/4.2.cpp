#include <iostream>
using namespace std;

int func(int N)
{
  cout << "func(" << N << ")を呼び出しました";
  if (N == 0)
  {
    return 0;
  }
  int result = N + func(N - 1);
  cout << N << "までの総和 = " << result << endl;
  return result;
}

int main()
{
  func(5);
}