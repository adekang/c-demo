#include <stdio.h>

// p[0] = *p

// ָ������
int main()
{
  int a[3] = {2, 5, 8};
  int *p;
  int j;
  p = a; // ��ָ�����p��ָ������Ŀ�ͷ
  // j = *p++;
  j = *p;
  p++;
  printf("a[0] =%d,j =%d,*p =%d\n", a[0], j, *p); // 2,2,5
  // j = p[0]++;
  j = *p;
  printf("֮ǰ��*p =%d\n", *p);
  printf("֮ǰ��a[1] =%d\n", a[1]);

  // *p++ ָ��������ռ���ǰ��һλ (*p)++ == p[0]++�����ַ���������һ
  *p++;
  printf("֮���*p =%d\n", *p);
  printf("֮���a[1] =%d\n", a[1]);

  printf("a[1] =%d,j =%d,*p =%d\n", a[1], j, *p); // 6,5,6

  return 0;
}