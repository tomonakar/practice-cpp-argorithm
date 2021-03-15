#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, b;
  cin >> a >> b;
  int c = (a + b) % 2;
  cout << (a + b) / 2 + c << endl;
}