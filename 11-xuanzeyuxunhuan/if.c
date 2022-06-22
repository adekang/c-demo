#include <stdio.h>

int main()
{

  int a;
  while (scanf("%d", &a) != EOF)
  {
    printf("a=%d\n", a);
    if (a > 0)
    {
      printf("a is bigger than 0 \n");
    }
    else if (a > 5)
    {
      printf("a is bigger than 5 \n");
    }
    else
    {
      printf("no no no\n");
    }
  }
  return 0;
}