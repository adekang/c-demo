#include <stdio.h>

struct student
{
  int num; //�ṹ���Ա
  char name[20];
  char sex;
};

// �ṹ��ָ��
int main()
{
  struct student s =
      {
          1001,
          "����",
          'm'};
  struct student *p;
  p = &s;

  printf("%d,%s,%c\n", (*p).num, (*p).name, (*p).sex);
  // ָ���Աѡ��
  printf("%d,%s,%c\n", p->num, p->name, p->sex);

  // �ṹ��ָ��ƫ��

  struct student arr[3] = {1001,
                           "����",
                           'm', 1005,
                           "����",
                           'm', 1008,
                           "����",
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