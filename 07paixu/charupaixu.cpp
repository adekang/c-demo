#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int ElemType;
typedef struct
{
  ElemType *elem; //����ָ��
  int TableLen;
} SSTable;

void ST_Init(SSTable &ST, int len)
{
  ST.TableLen = len + 1; // ʵ������11��Ԫ�صĿռ�
  ST.elem = (ElemType *)malloc(sizeof(ElemType) * ST.TableLen);
  int i;
  srand(time(NULL));
  for (i = 0; i < ST.TableLen; i++)
  {
    ST.elem[i] = rand() % 100; //�����11���������ǵ�һ��Ԫ����û���õ���
  }
}

void ST_print(SSTable ST)
{
  int i;
  for (i = 0; i < ST.TableLen; i++)
  {
    printf("%d ", ST.elem[i]);
  }
  printf("\n");
}

void swap(ElemType &a, ElemType &b)
{
  ElemType tmp;
  tmp = a;
  a = b;
  b = tmp;
}

void InsertSort(ElemType A[], int n)
{
  int i, j;
  for (i = 2; i <= n; i++) // ��0��Ԫ�����ڱ�����������
  {
    if (A[i] < A[i - 1])
    {
      A[0] = A[i]; // ��A[i]�ŵ���һ��λ�� Ҳ���ڱ�
      for (j = i - 1; A[0] < A[j]; j--)
      {
        A[j + 1] = A[j]; //�ƶ�Ԫ��
      }
      A[j + 1] = A[0]; // ���ݴ�Ԫ�ز��뵽��Ӧλ��
    }
  }
}

//��������
int main()
{
  SSTable ST;
  ST_Init(ST, 10); //ʵ��������11��Ԫ�ؿռ�
  ST_print(ST);
  InsertSort(ST.elem, 10);
  // MidInsertSort(ST.elem,10);
  // ShellSort(ST.elem,10);
  ST_print(ST);
  return 0;
}
