#include <stdio.h>

struct student
{
  int num;       //�ṹ���Ա
  char name[20]; // name ��ľ���һ����ַ
  char sex;
}; // ����һ���ṹ������

int main()
{
  struct student s;
  scanf("%d%s %c", &s.num, s.name, &s.sex);
  printf("%d %s %c \n", s.num, s.name, s.sex);
}