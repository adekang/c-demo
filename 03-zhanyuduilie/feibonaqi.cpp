#include <stdio.h>

int Fib(int num)
{
  if (num == 0)
  {
    return 0;
  }
  else if (num == 1)
  {
    return 1;
  }
  else
  {
    return Fib(num - 1) + Fib(num - 2);
  }
}

// 斐波那契数列
int main()
{

  int num;
  while (scanf("%d", &num) != EOF)
  {
    printf("总和：%d\n", num, Fib(num));
  }

  return 0;
}