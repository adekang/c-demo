#include <stdio.h>

// 关系运算符 > < >= <= == !=
// 关系运算符的返回值是一个布尔值
// 一切非零值为真，零为假
int main()
{
  int a, b;
  a = 4, b = 5;
  if (a > 3 && b > 3)
  {
    printf("true");
  }
  else
  {
    printf("false");
  }

  return 0;
}

// 逻辑运算符 && || !
// && 左右两边都为真才为真
// || 左右两边都为假才为假
// 真假取反 ！