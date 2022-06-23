#include <stdio.h>
// 数组打印

void print(int arr[], int len)
{
  // 直接修改数组
  arr[0] = 200;
  for (int i = 0; i < 5; i++)
  {
    /* code */
    printf("a[%d]=%d\n", i, arr[i]);
  }
}

int main()
{

  int a[5] = {1, 2, 3, 4, 5};
  print(a, 5);

  return 0;
}