#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef int ElemType;
typedef struct
{
  ElemType *elem; //����ָ��
  int TableLen;
} SSTable;

void ST_Init(SSTable &ST, int len)
{
  ST.TableLen = len;
  ST.elem = (ElemType *)malloc(sizeof(ElemType) * ST.TableLen);
  int i;
  srand(time(NULL));
  for (i = 0; i < ST.TableLen; i++)
  {
    ST.elem[i] = rand() % 100; //�����11���������ǵ�һ��Ԫ����û���õ���
  }
}

void swap(ElemType &a, ElemType &b)
{
  ElemType tmp;
  tmp = a;
  a = b;
  b = tmp;
}
void SelectSort(ElemType A[], int n)
{
  int i, j, k;
  for (i = 0; i < n - 1; i++)
  {
    k = i;
    for (j = i + 1; j < n; j++)
    {
      if (A[j] < A[k])
        k = j;
    }
    swap(A[i], A[k]);
  }
}

void AdjustDown(ElemType A[], int k, int len)
{
  int i;
  // A[0]�൱��һ���м����
  A[0] = A[k];
  for (i = 2 * k; i <= len; i *= 2)
  {
    if (i < len && A[i] < A[i + 1]) //���ӽڵ������ӽڵ�Ƚϴ�С
      i++;
    if (A[0] >= A[i])
      break;
    else
    {
      A[k] = A[i];
      k = i;
    }
  }
  A[k] = A[0];
}

void BuildMaxHeap(ElemType A[], int len)
{
  int i;
  for (i = len / 2; i > 0; i--)
  {
    AdjustDown(A, i, len);
  }
}

void HeapSort(ElemType A[], int len)
{
  int i;
  BuildMaxHeap(A, len); //�����󶥶�
  for (i = len; i > 1; i--)
  {
    swap(A[i], A[1]);
    AdjustDown(A, 1, i - 1);
  }
}

// ����������ʹ���Ϊ�󶥶�
void AdjustDown1(ElemType A[], int k, int len)
{
  int dad = k;
  int son = 2 * dad + 1; //�����±�
  // ������Ӵ��ڣ������ӵ�ֵ���ڸ��ڵ��ֵ����������Ϊ���ڵ�
  while (son <= len)
  {
    // ��û���Һ��� �Ƚ����Һ���ѡ���
    if (son + 1 <= len && A[son] < A[son + 1])
    {
      son++;
    }
    // �����Ǵ��ڸ��׵ľͽ���
    if (A[son] > A[dad])
    {
      swap(A[son], A[dad]);
      // ������һ��ѭ��
      dad = son;
      // ����son���±�
      son = 2 * dad + 1;
    }
    else
    {
      // û�н���
      break;
    }
  }
}

void HeapSort1(ElemType A[], int len)
{
  int i;
  for (i = len / 2; i >= 0; i--)
  {
    AdjustDown1(A, i, len);
  }
  swap(A[0], A[len]); // ��������Ԫ�غ����һ��Ԫ��
  for (i = len - 1; i > 0; i--)
  {
    AdjustDown1(A, 0, i); // ʣ�µ�Ԫ�����¹����󶥶�
    swap(A[0], A[i]);     // ��������Ԫ�غͱ�����һ��Ԫ��
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

// ������
int main()
{
  SSTable ST;
  ElemType A[10] = {64, 94, 95, 79, 69, 84, 18, 22, 12, 99};
  ST_Init(ST, 10); //��ʼ��
  memcpy(ST.elem, A, sizeof(A));
  ST_print(ST);
  // SelectSort(ST.elem, 10);
  HeapSort(ST.elem, 9); //���Ԫ�ز���������
  // HeapSort1(ST.elem, 9); //����Ԫ�ز�������
  ST_print(ST);
  return 0;
}
