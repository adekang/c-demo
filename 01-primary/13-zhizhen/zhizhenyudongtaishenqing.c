#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 指针与动态内存申请

int main()
{
  int i; // 申请的空间大小
  char *p;
  scanf("%d", &i); // 输入申请的空间大小
  // p 是取其地址
  // （malloc 申请空间的单位是字节）
  // (char *) 强制类型转换
  p = (char *)malloc(i); // 使用 malloc 动态申请空间
  strcpy(p, "malloc success");
  puts(p);
  free(p);  // 释放 p 但是p的值不会变
  p = NULL; // 如果不把p值为NULL， 把p称为野指针

  printf("free success\n");
  return 0;
}