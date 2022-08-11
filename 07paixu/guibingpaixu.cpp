#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 7

typedef int ElemType;

void Print(ElemType A[], int n)
{
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", A[i]);
  printf("\n");
}

void Merge(ElemType A[], int low, int mid, int high)
{
  ElemType B[N]; // 为了降低操作次数
  int i, j, k;
  for (k = low; k <= high; k++) // 初始化B数组
  {
    B[k] = A[k];
  }
  for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
  {
    if (B[i] <= B[j])
    {
      A[k] = B[i++];
    }
    else
    {
      A[k] = B[j++];
    }
  }
  //如果有剩余的元素，则将剩余的元素拷贝到A数组中
  while (i <= mid)
    A[k++] = B[i++];
  while (j <= high)
    A[k++] = B[j++];
}

void MergeSort(ElemType A[], int low, int high)
{
  if (low < high)
  {
    int mid = (low + high) / 2;
    MergeSort(A, low, mid);
    MergeSort(A, mid + 1, high);
    Merge(A, low, mid, high);
  }
}
// 归并排序
int main()
{
  int A[7] = {49, 38, 65, 97, 76, 13, 27};
  MergeSort(A, 0, 6);
  // 打印A
  Print(A, N);
  return 0;
}