#include <stdio.h>

int number(int n)
{
  if (n == 1)
  {
    return 1;
  }
  return n * number(n - 1);
}

// �ݹ�
int main()
{
  int a = number(5);
  printf("%d\n", a);
  return 0;
}