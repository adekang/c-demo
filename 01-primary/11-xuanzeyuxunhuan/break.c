#include <stdio.h>

// break
int main()
{
  int i, total;

  for (i = 1, total = 0; i <= 100; i++)
  {
    if (total > 2000)
    {
      break;
    }
    total = total + i;
  }
  printf("total =%d , i =%d \n", total, i);

  return 0;
}