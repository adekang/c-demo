#include <stdio.h>

// typedef ���ڶ����������ƣ��������ڶ������ͣ�Ҳ�������ڶ����������ơ�
//  ��������������á�

//���ṹ���������������stu, ���˽ṹ��ָ�����͵ı�������pstu

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
  // stu* p1,��ôp1Ҳ��һ���ṹ��ָ��
  INTEGER i = 110;

  return 0;
}