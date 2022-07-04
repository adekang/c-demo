#include <stdio.h>

int main()
{
  int i = 123;
  float f = 1.23;
  // 定义一个字符型变量
  char s = 'a';
  char c[50] = "adekang";
  //  %d以十进制输出整数
  printf("i=%d\n", i);
  //  %f以浮点数形式输出
  printf("f=%f\n", f);
  //  %c以字符形式输出
  printf("f=%c\n", s);
  printf("f=%d\n", s);
  printf("f=%s\n", c);

  return 0;
}