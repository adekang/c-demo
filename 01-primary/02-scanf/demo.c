// 鏍煎紡鍖栬緭鍏?
#include <stdio.h>

// %c：一个单个的字符。
// %f：小数（包含float类型和double类型）。
// %d：十进制整数
// %s：字符串。

int main()
{
  int a;
  float b;
  char c;
  char str[10];

  scanf("%d%f", &a, &b);
  // getchar
  getchar();
  scanf("%c", &c);
  scanf("%s", str);

  printf("int var a = %d\n", a);
  printf("float var b = %f\n", b);
  printf("char var c = %c\n", c);
  printf("string var str = %s\n", str);

  return 0;
}