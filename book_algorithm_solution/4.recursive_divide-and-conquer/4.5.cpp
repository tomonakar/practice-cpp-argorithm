// フィボナッチ数列
int fibo(int N)
{
  if (N == 0)
  {
    return 0;
  }
  else if (N == 1)
  {
    return 1;
  }

  return fibo(N - 1) + fibo(N - 2);
}