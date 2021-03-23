// 1 から Nまでの総和を計算
int func(int N)
{
  if (N == 0)
    return 0;
  return N + func(N - 1);
}