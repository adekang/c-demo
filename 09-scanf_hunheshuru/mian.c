//  scanf �������

#include <stdio.h>
// �������ʱÿ����%c�������һ���ո�
int main()
{
  int i;
  char c;
  float f;
  int ret;
  ret = scanf("%d %c%f", &i, &c, &f);
  printf("%d ,%c, %f\n", i, c, f);

  return 0;
}