#include <stdio.h>

// p[0] = *p

// 指针自增
int main()
{
  int a[3] = {2, 5, 8};
  int *p;
  int j;
  p = a; // 让指针变量p，指向数组的开头
  // j = *p++;
  j = *p;
  p++;
  printf("a[0] =%d,j =%d,*p =%d\n", a[0], j, *p); // 2,2,5
  // j = p[0]++;
  j = *p;
  printf("之前的*p =%d\n", *p);
  printf("之前的a[1] =%d\n", a[1]);

  // *p++ 指的是这个空间向前加一位 (*p)++ == p[0]++这个地址里面的数加一
  *p++;
  printf("之后的*p =%d\n", *p);
  printf("之后的a[1] =%d\n", a[1]);

  printf("a[1] =%d,j =%d,*p =%d\n", a[1], j, *p); // 6,5,6

  return 0;
}