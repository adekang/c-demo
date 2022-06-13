// 格式化输入
#include <stdio.h>

int main()
{
  int a;
  float b;
  char c;
  char str[10];

  scanf("%d", &a);
  scanf("%f", &b);
  // getchar 是一个把输入缓冲区的内容读取到缓冲区的函数，
  getchar();
  scanf("%c", &c);
  scanf("%s", str);

  printf("int var = %d\n", a);
  printf("float var = %f\n", b);
  printf("char var = %c\n", c);
  printf("string var = %s\n", str);

  return 0;
}