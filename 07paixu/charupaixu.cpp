#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>

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

// �۰��������
void MidInsertSort(ElemType A[], int n)
{
  int i, j, low, high, mid;
  for (i = 2; i <= n; i++)
  {
    A[0] = A[i]; // ��A[i]�ŵ���һ��λ�� Ҳ���ڱ�
    low = 1;
    high = i - 1;       // low�������еĿ�ʼ��high�������е����
    while (low <= high) // ��ͨ�����ֲ����ҵ�������λ��
    {
      mid = (low + high) / 2;
      if (A[mid] > A[0])
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
    for (j = i - 1; j >= high + 1; --j)
    {
      A[j + 1] = A[j];
    }
    A[high + 1] = A[0];
  }
}

void ShellSort(ElemType A[], int n)
{
  int dk, i, j;
  for (dk = n / 2; dk >= 1; dk = dk / 2) //�����仯
  {
    for (i = dk + 1; i <= n; ++i) //��dkΪ�������в�������
    {
      if (A[i] < A[i - dk])
      {
        A[0] = A[i]; // �ڱ�
        for (j = i - dk; j > 0 && A[0] < A[j]; j = j - dk)
        {
          A[j + dk] = A[j];
        }
        A[j + dk] = A[0];
      }
    }
  }
}
//��������
int main()
{
  SSTable ST;
  ElemType A[10] = {64, 34, 25, 12, 22, 11, 90, 54, 67, 88};
  ST_Init(ST, 10); //ʵ��������11��Ԫ�ؿռ�
  memcpy(ST.elem + 1, A, sizeof(A));
  ST_print(ST);

  // ֱ�Ӳ�������
  // InsertSort(ST.elem, 10);

  // �۰��������
  // MidInsertSort(ST.elem, 10);

  // ϣ������
  ShellSort(ST.elem, 10);
  ST_print(ST);
  return 0;
}
