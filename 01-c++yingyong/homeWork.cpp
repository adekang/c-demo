#include <stdio.h>
#include <stdlib.h>

// �������C++����
// *&p ����һ�����ã�ָ��һ��ָ�룬ָ���ֵ��ָ��ĵ�ַ
void modify_pointer(char *&p) // ���������õ�ָ��
{
  p = (char *)malloc(20);
  gets(p);
}

// C++������ҵ
int main()
{
  char *p;
  modify_pointer(p);
  puts(p);
  return 0;
}