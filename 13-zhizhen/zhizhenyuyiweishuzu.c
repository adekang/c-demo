#include <stdio.h>

void change(char *d)
{
  *d = 'H';
  d[1] = 'E';
  // 等于上面的操作
  // *(d + 1) = 'E';
  *(d + 2) = 'L';
}
// 指针与一维数组
int main()
{
  char c[10] = "hello";
  change(c);
  puts(c);
  return 0;
}