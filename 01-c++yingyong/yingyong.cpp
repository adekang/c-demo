#include <stdio.h>
#include <stdlib.h>

// C++����

// ��&д���βε�λ����C++���﷨����Ϊ���ã����ʱ�����b�������������ʹ��a�ȼ۵�
int modifyNum(int &num)
{
  num += 1;
  return num;
}
// ���Ӻ����ڲ���p������������p�ַ�һ��
void modify_pointer(int *&p1)
{
  // ���ܽ� "void *" ���͵�ֵ���䵽 "int *" ���͵�ʵ��
  // ǿת����
  p1 = (int *)malloc(20);
  p1[0] = 5;
}

int main()
{
  int a = 10;
  modifyNum(a);
  printf("a = %d\n", a);
  int *p = NULL;
  modify_pointer(p);
  printf("p[0] = %d\n", *p);
  return 0;
}