#include <stdio.h>

// ָ��
int main()
{
  int i = 5;
  // &�ǣ����ã�ȡ��ַ ָ������ĳ�ʼ��һ����ĳ������ȡ��ַ
  int *i_pointer = &i;
  // || *�ǽ�����ַ ���ֻ�� i_pointer �������ĵ�ַ
  printf("%d\n", *i_pointer);
  return 0;
}