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
  ElemType B[N]; // Ϊ�˽��Ͳ�������
  int i, j, k;
  for (k = low; k <= high; k++) // ��ʼ��B����
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
  //�����ʣ���Ԫ�أ���ʣ���Ԫ�ؿ�����A������
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
// �鲢����
int main()
{
  int A[7] = {49, 38, 65, 97, 76, 13, 27};
  MergeSort(A, 0, 6);
  // ��ӡA
  Print(A, N);
  return 0;
}