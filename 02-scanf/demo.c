// 格式化输�?
#include <stdio.h>

// %c��һ���������ַ���
// %f��С��������float���ͺ�double���ͣ���
// %d��ʮ��������
// %s���ַ�����

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