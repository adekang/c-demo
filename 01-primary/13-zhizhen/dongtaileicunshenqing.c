#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ָ���붯̬�ڴ�����

// char * �����ķ���ֵ
char *print_stack()
{
  char c[] = "I am print_stack";
  puts(c);
  return c;
  // ����ᱨ�� ԭ����ջ�ռ�����ź��������н������ͷ�
}

char *print_malloc()
{
  //
  //  ����ǿת
  char *p = (char *)malloc(30);
  strcpy(p, "I am print_malloc");
  puts(p);
  return p;
}

int main()
{

  char *p;
  p - print_stack();  // ջ�ռ�����ź��������н������ͷ�
  p = print_malloc(); // �ѿռ䲻�����Ӻ����Ľ������ͷţ������Լ�free
  puts(p);
  return 0;
}