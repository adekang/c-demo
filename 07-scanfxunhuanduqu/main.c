#include <stdio.h>

// 清空缓冲区
int main()
{
  int i, ret;
  // scanf 发生错误时返回 EOF
  // 出错情况 在行首输入ctrl+z 三次
  while (rewind(stdin), (ret = scanf("%d", &i)) != EOF)
  {
    printf("%d\n", i);
  }

  return 0;
}