#include <stdio.h>

// 作业
int main()
{
  int a, b, c, temp;
  scanf("%d", &a);
  b = 0;
  c = a;
  while (a)
  {
    temp = a % 10;
    b = b * 10 + temp;
    a = a / 10;
  }
  printf("b = %d\n", b);
  printf("a = %d\n", a);
  if (c == b)
  {
    printf("对称\n");
  }
  else
  {
    printf("不对称\n");
  }

  return 0;
}