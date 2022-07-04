//  scanf 混合输入

#include <stdio.h>
// 混合输入时每次在%c后面加上一个空格
int main()
{
  int i;
  char c;
  float f;
  int ret;
  ret = scanf("%d %c%f", &i, &c, &f);
  printf("%d ,%c, %f\n", i, c, f);

  return 0;
}