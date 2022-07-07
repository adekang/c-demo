#include <stdio.h>

struct student
{
  int num;       //结构体成员
  char name[20]; // name 存的就是一个地址
  char sex;
}; // 申明一个结构体类型

int main()
{
  struct student s;
  scanf("%d%s %c", &s.num, s.name, &s.sex);
  printf("%d %s %c \n", s.num, s.name, s.sex);
}