#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, A;
  cin >> N >> A;
  int mass = N * N;
  int black = mass - A;
  cout << black;
}