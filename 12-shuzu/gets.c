#include <stdio.h>

void print(char a[])
{
}
// gets
int main()
{
  char c[20]; //字符数组的数组名里存的就是字符数组的起始地址

  gets(c);
  puts(c);
  return 0;
}