#include <stdio.h>
#include <stdlib.h>

// 这里就是C++引用
// *&p 就是一个引用，指向一个指针，指针的值是指针的地址
void modify_pointer(char *&p) // 参数是引用的指针
{
  p = (char *)malloc(20);
  gets(p);
}

// C++引用作业
int main()
{
  char *p;
  modify_pointer(p);
  puts(p);
  return 0;
}