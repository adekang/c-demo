#include <stdio.h>

struct student
{
  int num; //�ṹ���Ա
  char name[20];
  char sex;
  float score;
};

// �ṹ��
int main()
{
  struct student s =
      {
          1001,
          "����",
          'm',
          20};
  struct student arr[3];
  int i;

  for (i = 0; i < 3; i++)
  {
    scanf("%d%s %c%f", &arr[i].num, arr[i].name, &arr[i].sex, &arr[i].score);
  }
  for (i = 0; i < 3; i++)
  {
    printf("%d,%s,%c,%5.2f\n", arr[i].num, arr[i].name, arr[i].sex, arr[i].score);
  }

  return 0;
}