#include <stdio.h>

int main()
{
  int i = 123;
  float f = 1.23;
  // ����һ���ַ��ͱ���
  char s = 'a';
  char c[50] = "adekang";
  //  %d��ʮ�����������
  printf("i=%d\n", i);
  //  %f�Ը�������ʽ���
  printf("f=%f\n", f);
  //  %c���ַ���ʽ���
  printf("f=%c\n", s);
  printf("f=%d\n", s);
  printf("f=%s\n", c);

  return 0;
}