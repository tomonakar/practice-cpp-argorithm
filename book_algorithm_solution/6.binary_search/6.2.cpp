#include <iostream>
using namespace std;

// 一般化した二分探索ほうの基本形

// xが条件を満たすかどうかでboolを返す
bool P(int x)
{
}

// P(x) = true となる最小の整数xを返す
int binary_search()
{
  int left, right;

  while (right - left > 1)
  {
    int mid = left + (right - left) / 2;
    if (P(mid))
    {
      right = mid;
    }
    else
    {
      left = mid;
    }
  }
  return right;
}
