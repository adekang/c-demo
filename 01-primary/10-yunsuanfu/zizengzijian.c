#include <stdio.h>
// 自增自减运算符
// 前加加前减减 正常运算即可
int main()
{

  int i = -1;
  int j;
  // 后加加拆2步
  // j=i>-1;i++
  j = i++ > 1;
  printf("%d\n", j);

  return 0;
}