//  ËãÊıÔËËã·û
#include <stdio.h>

int main()
{
  int a, b;
  scanf("%d", &a);

  while (a != 0)
  {
    /* code */
    printf("a=%d", a % 10);
    a = a / 10;
  }
  printf("½áÊøÀ²\n");
  return 0;
}