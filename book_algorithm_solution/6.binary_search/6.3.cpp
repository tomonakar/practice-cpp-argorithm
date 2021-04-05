#include <iostream>
using namespace std;

// 年齢あてゲーム
int main()
{
  cout << "Start Game!" << endl;

  // Aさんの数の候補を表す区間を、[left, right) と表す
  int left = 20, right = 40;

  // Aさんの数を 1つに絞れないうちは繰り返す
  while (right - left > 1)
  {
    int mid = left + (right - left) / 2;

    // mid 以上かを聞いて、回答を yes/no で受け取る
    cout << "Is the age less than" << mid << "? (yes / no)" << endl;
    string ans;
    cin >> ans;

    // 回数に応じて、ありうる数の範囲を絞る
    if (ans == "yes")
    {
      right = mid;
    }
    else
    {
      left = mid;
    }
  }
  // 回答
  cout << "The age is " << left << "!" << endl;
}