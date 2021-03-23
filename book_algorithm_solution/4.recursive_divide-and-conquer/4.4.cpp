#include <iostream>
using namespace std;

// ユークリッド互助法
// @see https://ja.wikipedia.org/wiki/%E3%83%A6%E3%83%BC%E3%82%AF%E3%83%AA%E3%83%83%E3%83%89%E3%81%AE%E4%BA%92%E9%99%A4%E6%B3%95
int GCD(int m, int n)
{
  if (n == 0)
  {
    return m
  }

  return GCD(n, m % n);
}