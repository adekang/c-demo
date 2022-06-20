//  printf 混合输入

#include <stdio.h>
// 混合输入时每次在%c后面加上一个空格
int main()
{
  printf("name = %s,age = %d ,sex=%c ,score =%5.2f\n", "ade", 34, 'm', 98.5);
  return 0;
}