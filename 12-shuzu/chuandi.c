#include <stdio.h>

void print(char a[])
{
  int i = 0;
  while (a[i])
  {
    printf("a[%d]= %c\n", i, a[i]);
    i++;
  }
  printf("\n");
}
// �ַ�����Ĵ���
int main()
{
  char c[10] = "hello";
  print(c);
  return 0;
}