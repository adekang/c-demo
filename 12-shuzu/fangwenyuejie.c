#include <stdio.h>

// 访问越界
int main()
{
  int j = 10;

  int a[5] = {1, 2, 3, 4, 5};

  a[5] = 20;
  a[7] = 21;
  int i = 5;
  // j打印出来是21
  printf("a的第一个数字=%d\n", j);
  return 0;
}