#include <stdio.h>
#include <string.h>

int main()
{
  char c[100], d[100];
  gets(c);
  int len = strlen(c);
  int i, j;
  for (i = strlen(c) - 1, j = 0; i >= 0; i--, j++)
  {
    d[j] = c[i];
  }
  d[j] = '\n';
  int res = strcmp(c, d);

  if (res < 0)
  {
    printf("%d\n", -1);
  }
  else if (res > 0)
  {
    printf("%d\n", 1);
  }
  else
  {
    printf("%d\n", 0);
  }
  puts(d);
  return 0;
}
