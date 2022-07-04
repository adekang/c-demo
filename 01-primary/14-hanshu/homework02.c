#include <stdio.h>

int number(int n)
{
  if (n == 1 || 2 == n)
  {
    return n;
  }

  return number(n - 1) + number(n - 2);
}

// µİ¹é
int main()
{
  int a = number(7);
  printf("%d\n", a);
  return 0;
}