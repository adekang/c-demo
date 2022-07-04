#include <stdio.h>

int main()
{
  char i = 5;
  // i 为整型
  float j = i / 2;
  // 强制转换为浮点型
  float k = (float)i / 2;

  printf("%f\n", j);
  printf("%f\n", k);
}