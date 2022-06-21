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
    printf("true\n");
  }
  else
  {
    printf("false\n");
  }
  //  判断2个浮点数是否相等
  float f = 234.56;
  if (f - 234.56 > -0.000001 && f - 234.56 < 0.000001)
  {
    printf("true\n");
  }
  else
  {
    printf("false\n");
  }
  return 0;
}

// 逻辑运算符 && || !
// && 左右两边都为真才为真
// || 左右两边都为假才为假
// 真假取反 ！