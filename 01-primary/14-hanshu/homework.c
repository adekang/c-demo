#include <stdio.h>

int change(int *p)
{
  *p /= 2;
}
// ��ҵ
int main()
{
  int i;
  scanf("%d", &i);

  change(&i);
  printf("%d\n", i);

  return 0;
}