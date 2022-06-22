#include <stdio.h>

// while
int main()
{
  int i = 1;
  int total = 0;
  while (i <= 100)
  {
    total = total + i;
    i++;
  }
  printf("total = %d\n", total);
  return 0;
}