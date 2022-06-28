#include <stdio.h>

void change(int *j) // j 形参 j=&i
{
  *j = 5;
}
// 指针传递
int main()
{
  int i = 10; //  i 局部变量
  printf("before change , i = %d\n", i);
  change(&i); //函数调用时，把&i称为实参
  printf("after change , i = %d\n", i);
  return 0;
}