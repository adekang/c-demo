
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// homework
int main()
{
  int n;
  char *p;
  char c;

  scanf("%d", &n);
  p = (char *)malloc(n);
  scanf("%c", &c); // ���� \n
  gets(p);
  puts(p);
  return 0;
}