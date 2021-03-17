#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> data(5);
  for (int i = 0; i < 5; i++)
  {
    cin >> data.at(i);
  }

  string ans = "NO";
  for (int i = 0; i < 4; i++)
  {
    if (data.at(i) == data.at(i + 1))
    {
      ans = "YES";
    }
  }

  cout << ans << endl;
}