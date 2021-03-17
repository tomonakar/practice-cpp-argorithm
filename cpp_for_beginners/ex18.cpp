#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, M; // N人、M試合
  cin >> N >> M;
  vector<int> A(M), B(M); // A勝ち、B負け
  for (int i = 0; i < M; i++)
  {
    cin >> A.at(i) >> B.at(i);
  }

  vector<vector<char> > table(N, vector<char>(N, '-'));

  for (int i = 0; i < M; i++)
  {
    A.at(i)--;
    B.at(i)--;
    table.at(A.at(i)).at(B.at(i)) = 'o';
    table.at(B.at(i)).at(A.at(i)) = 'x';
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cout << table.at(i).at(j);
      if (j == N - 1)
      {
        cout << endl;
      }
      else
      {
        count << " ";
      }
    }
  }
}