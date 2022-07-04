#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 指针与动态内存申请

// char * 函数的返回值
char *print_stack()
{
  char c[] = "I am print_stack";
  puts(c);
  return c;
  // 这里会报错 原因是栈空间会随着函数的运行结束而释放
}

char *print_malloc()
{
  //
  //  必须强转
  char *p = (char *)malloc(30);
  strcpy(p, "I am print_malloc");
  puts(p);
  return p;
}

int main()
{

  char *p;
  p - print_stack();  // 栈空间会随着函数的运行结束而释放
  p = print_malloc(); // 堆空间不会随子函数的结束而释放，必须自己free
  puts(p);
  return 0;
}