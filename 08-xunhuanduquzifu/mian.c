#include <stdio.h>

// ѭ����ȡ�ַ���
int main()
{
  char c;

  while (scanf("%c", &c) != EOF)
  {
    if (c != '\n')
    {
      printf("%c\n", c);
    }
    else
    {
      printf("\n");
    }
  }

  return 0;
}