#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 2点(x1, y1) (x2, y2)の距離を求める
// @see https://www.geisya.or.jp/~mwm48961/math/distance1j.htm
double calc_dist(double x1, double y1, double x2, double y2)
{
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
  int N;
  cin >> N;
  vector<double> x(N), y(N);
  for (int i = 0; i < N; i++)
    cin >> x[i] >> y[i];

  // 求める値を十分大きな値で初期化する
  double minimum_dist = 10000000.0;

  // 探索開始
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      // (x[i], y[i]) と　(x[j], y[j]) との距離
      double dist_i_j = calc_dist(x[i], y[i], x[j], y[j]);

      // 暫定最小値
      if (dist_i_j < minimum_dist)
      {
        minimum_dist = dist_i_j;
      }
    }
  }

  cout << minimum_dist << endl;
}