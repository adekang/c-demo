#include <stdio.h>

// ָ��ƫ��
int main()
{
  int a[5] = {1,
              2,
              3,
              4,
              5};
  int *p; //��һ��ָ���������ȡֵ���õ����������������
  p = a;
  for (int i = 0; i < 5; i++)
  {
    /* ��ƫ����ȡ��ַ */
    printf("*p = %d \n", *(p + i));
  }

  return 0;
}