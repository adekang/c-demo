#include <stdio.h>
#include <string.h>

// ��const���δ�������ط����Է�һ�ַ�������

int main()
{
  char c[20] = "hello"; //�ַ���������������ľ����ַ��������ʼ��ַ

  //  �ַ����ĳ���
  printf("����c�ַ����ĳ��� = %d\n", strlen(c));
  // �����ַ���
  char d[20];
  strcpy(d, c);
  printf("����d = %s\n", d);

  // �Ƚ�2���ַ���,��Ӧλ�õ�ascii��ֵ

  int res = strcmp("a", "b");
  printf("�Ƚ�2���ַ���:%d \n", res);

  // ƴ��2���ַ��� Ŀ������Ҫ�ܹ�����ƴ�Ӻ���ַ���
  strcat(c, ":adekang");
  printf("����d = %s\n", c);

  return 0;
}