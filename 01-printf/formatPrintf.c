#include <stdio.h>

int main()
{
  //  注意：printf函数的第一个参数是一个字符串，后面的参数是可变参数，
  int a = 10;
  float b = 10.5;
  char c = 'c';
  //  字串中的引号必须是双引号，否则会报错。
  char str[50] = "string";

  printf("int var = %d\n", a);
  printf("float var = %f\n", b);
  printf("char var = %c\n", c);
  printf("string var = %s\n", str);
  return 0;
}

// 格式控制符  %d, %f, %c, %s