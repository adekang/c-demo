#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ָ���붯̬�ڴ�����

int main()
{
  int i; // ����Ŀռ��С
  char *p;
  scanf("%d", &i); // ��������Ŀռ��С
  // p ��ȡ���ַ
  // ��malloc ����ռ�ĵ�λ���ֽڣ�
  // (char *) ǿ������ת��
  p = (char *)malloc(i); // ʹ�� malloc ��̬����ռ�
  strcpy(p, "malloc success");
  puts(p);
  free(p);  // �ͷ� p ����p��ֵ�����
  p = NULL; // �������pֵΪNULL�� ��p��ΪҰָ��

  printf("free success\n");
  return 0;
}