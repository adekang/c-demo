#include <stdio.h>

// ��ҵ
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
    printf("�Գ�\n");
  }
  else
  {
    printf("���Գ�\n");
  }

  return 0;
}