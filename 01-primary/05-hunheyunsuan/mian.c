#include <stdio.h>

int main()
{
  char i = 5;
  // i Ϊ����
  float j = i / 2;
  // ǿ��ת��Ϊ������
  float k = (float)i / 2;

  printf("%f\n", j);
  printf("%f\n", k);
}