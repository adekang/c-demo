#include <stdio.h>
#include <string.h>

// 有const修饰代表这个地方可以放一字符串常量

int main()
{
  char c[20] = "hello"; //字符数组的数组名里存的就是字符数组的起始地址

  //  字符串的长度
  printf("数组c字符串的长度 = %d\n", strlen(c));
  // 复制字符串
  char d[20];
  strcpy(d, c);
  printf("数组d = %s\n", d);

  // 比较2个字符串,对应位置的ascii码值

  int res = strcmp("a", "b");
  printf("比较2个字符串:%d \n", res);

  // 拼接2个字符串 目标数组要能够容纳拼接后的字符串
  strcat(c, ":adekang");
  printf("数组d = %s\n", c);

  return 0;
}