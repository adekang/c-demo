#include <stdio.h>

struct student
{
  int num; //结构体成员
  char name[20];
  char sex;
};

// 结构体指针
int main()
{
  struct student s =
      {
          1001,
          "乐乐",
          'm'};
  struct student *p;
  p = &s;

  printf("%d,%s,%c\n", (*p).num, (*p).name, (*p).sex);
  // 指针成员选择
  printf("%d,%s,%c\n", p->num, p->name, p->sex);

  // 结构体指针偏移

  struct student arr[3] = {1001,
                           "乐乐",
                           'm', 1005,
                           "乐乐",
                           'm', 1008,
                           "乐乐",
                           'm'};

  p = arr;

  printf("___________________\n");
  int num;
  num = p->num++;
  printf("num = %d,p->num = %d\n", num, p->num);
  num = p++->num;
  printf("num = %d,p->num = %d\n", num, p->num);

  return 0;
}