#include <stdio.h>

void change(int *j) // j �β� j=&i
{
  *j = 5;
}
// ָ�봫��
int main()
{
  int i = 10; //  i �ֲ�����
  printf("before change , i = %d\n", i);
  change(&i); //��������ʱ����&i��Ϊʵ��
  printf("after change , i = %d\n", i);
  return 0;
}