#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>

typedef int ElemType;
typedef struct
{
  ElemType *elem; //�洢Ԫ�ص���ʼ��ַ
  int TableLen;   //Ԫ�ظ���
} SSTable;

void swap(ElemType &a, ElemType &b)
{
  ElemType tmp;
  tmp = a;
  a = b;
  b = tmp;
}

void ST_Init(SSTable &ST, int len)
{
  ST.TableLen = len;
  ST.elem = (ElemType *)malloc(sizeof(ElemType) * ST.TableLen);
  int i;
  srand(time(NULL)); // ���������
  for (i = 0; i < ST.TableLen; i++)
  {
    ST.elem[i] = rand() % 100; // ����0-99�������
  }
}

void BubbleSort(ElemType A[], int n)
{
  int i, j, flag;
  for (i = 0; i < n - 1; i++)
  {
    flag = 0;
    for (j = n - 1; j > i; j--)
    {
      if (A[j - 1] > A[j])
      {
        swap(A[j - 1], A[j]);
        flag = 1;
      }
    }
    if (flag == 0)
      break;
  }
}

int Partition(ElemType A[], int left, int right)
{
  int i, j;
  for (i = j = left; i < right; i++)
  {
    if (A[i] < A[right])
    {
      swap(A[i], A[j]);
      j++;
    }
  }
  swap(A[j], A[right]);
  return j;
}

void QuickSort(ElemType A[], int low, int high)
{
  if (low < high)
  {
    int pivot = Partition(A, low, high);
    QuickSort(A, low, pivot - 1);
    QuickSort(A, pivot + 1, high);
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
//ð���������������
int main()
{
  SSTable ST;
  ElemType A[10] = {64, 94, 95, 79, 69, 84, 18, 22, 12, 78};
  ST_Init(ST, 10);               //��ʼ��
  memcpy(ST.elem, A, sizeof(A)); //�ڴ濽���ӿ� ����copy�������飬���߸�����ʱ��Ҫ��memcpy
  ST_print(ST);
  BubbleSort(ST.elem, 10);
  printf("-----\n");
  ST_print(ST);
  QuickSort(ST.elem, 0, 9);
  printf("-----\n");
  ST_print(ST);
  return 0;
}
