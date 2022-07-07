#include <stdio.h>
#include <stdlib.h>

// C++引用

// 把&写到形参的位置是C++的语法，称为引用，这个时候操作b和在主函数里边使用a等价的
int modifyNum(int &num)
{
  num += 1;
  return num;
}
// 在子函数内操作p和主函数操作p手法一致
void modify_pointer(int *&p1)
{
  // 不能将 "void *" 类型的值分配到 "int *" 类型的实体
  // 强转类型
  p1 = (int *)malloc(20);
  p1[0] = 5;
}

int main()
{
  int a = 10;
  modifyNum(a);
  printf("a = %d\n", a);
  int *p = NULL;
  modify_pointer(p);
  printf("p[0] = %d\n", *p);
  return 0;
}