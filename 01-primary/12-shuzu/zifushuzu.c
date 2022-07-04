#include <stdio.h>

// 初始化字符数组时，一定要让字符数组的大小比看到的字符串的长度多1
// 字符数组 就是用来存字符串的
int main()
{
  char a[5] = "hello";
  char e[20], f[20];
  scanf("%s%s", e, f);
  printf("e = %s\n", e);
  printf("f = %s\n", f);
  return 0;
}