#include <stdio.h>

// typedef 用于定义类型名称，可以用于定义类型，也可以用于定义类型名称。
//  就是起别名的作用。

//给结构体类型起别名，叫stu, 起了结构体指针类型的别名，叫pstu

typedef struct student
{
  int age;
  char name[10];
  char sex;
} stu, *pstu;

typedef int INTEGER;
int main()
{

  stu s = {1001,
           "ade",
           'm'};
  pstu p;
  // stu* p1,那么p1也是一个结构体指针
  INTEGER i = 110;

  return 0;
}