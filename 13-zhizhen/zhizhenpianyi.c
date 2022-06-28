#include <stdio.h>

// 指针偏移
int main()
{
  int a[5] = {1,
              2,
              3,
              4,
              5};
  int *p; //对一个指针变量进行取值，得到的类型是其基类型
  p = a;
  for (int i = 0; i < 5; i++)
  {
    /* 先偏移在取地址 */
    printf("*p = %d \n", *(p + i));
  }

  return 0;
}