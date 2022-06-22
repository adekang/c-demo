#include <stdio.h>

// continue
int main()
{
  int i, total;

  for (i = 1, total = 0; i <= 100; i++)
  {
    if (i % 2 == 0)
    {
      // 提前结束本轮循环
      continue;
    }
    else
    {
      total = total + i;
    }
  }
  printf("total = %d\n", total);

  return 0;
}