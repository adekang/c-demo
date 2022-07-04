#include <stdio.h>

// 指针
int main()
{
  int i = 5;
  // &是（引用）取地址 指针变量的初始化一定是某个变量取地址
  int *i_pointer = &i;
  // || *是解析地址 如果只是 i_pointer 就是其存的地址
  printf("%d\n", *i_pointer);
  return 0;
}