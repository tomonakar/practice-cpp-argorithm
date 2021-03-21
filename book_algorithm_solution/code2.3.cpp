#include <iostream>
using namespace std;

// 偶数の列挙

int main()
{
  int N;
  cin >> N;

  for (int i = 2; i <= N; i += 2)
  {
    cout << i << endl;
  }
}