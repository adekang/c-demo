#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef int ElemType;
typedef struct
{
  ElemType *elem; //整型指针
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
    ST.elem[i] = rand() % 100; //随机了11个数，但是第一个元素是没有用到的
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
  // A[0]相当于一个中间变量
  A[0] = A[k];
  for (i = 2 * k; i <= len; i *= 2)
  {
    if (i < len && A[i] < A[i + 1]) //左子节点与右子节点比较大小
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
  BuildMaxHeap(A, len); //建立大顶堆
  for (i = len; i > 1; i--)
  {
    swap(A[i], A[1]);
    AdjustDown(A, 1, i - 1);
  }
}

// 调整子树，使其成为大顶堆
void AdjustDown1(ElemType A[], int k, int len)
{
  int dad = k;
  int son = 2 * dad + 1; //左孩子下标
  // 如果左孩子存在，且左孩子的值大于父节点的值，则将左孩子设为父节点
  while (son <= len)
  {
    // 有没有右孩子 比较左右孩子选大的
    if (son + 1 <= len && A[son] < A[son + 1])
    {
      son++;
    }
    // 孩子是大于父亲的就交换
    if (A[son] > A[dad])
    {
      swap(A[son], A[dad]);
      // 继续下一轮循环
      dad = son;
      // 更新son的下标
      son = 2 * dad + 1;
    }
    else
    {
      // 没有交换
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
  swap(A[0], A[len]); // 交换顶部元素和最后一个元素
  for (i = len - 1; i > 0; i--)
  {
    AdjustDown1(A, 0, i); // 剩下的元素重新构建大顶堆
    swap(A[0], A[i]);     // 交换顶部元素和本次最一个元素
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

// 堆排序
int main()
{
  SSTable ST;
  ElemType A[10] = {64, 94, 95, 79, 69, 84, 18, 22, 12, 99};
  ST_Init(ST, 10); //初始化
  memcpy(ST.elem, A, sizeof(A));
  ST_print(ST);
  // SelectSort(ST.elem, 10);
  HeapSort(ST.elem, 9); //零号元素不参与排序
  // HeapSort1(ST.elem, 9); //所有元素参与排序
  ST_print(ST);
  return 0;
}
