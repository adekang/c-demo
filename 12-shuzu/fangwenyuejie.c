#include <stdio.h>

// ����Խ��
int main()
{
  int j = 10;

  int a[5] = {1, 2, 3, 4, 5};

  a[5] = 20;
  a[7] = 21;
  int i = 5;
  // j��ӡ������21
  printf("a�ĵ�һ������=%d\n", j);
  return 0;
}