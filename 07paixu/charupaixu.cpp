#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>

typedef int ElemType;
typedef struct
{
  ElemType *elem; //整型指针
  int TableLen;
} SSTable;

void ST_Init(SSTable &ST, int len)
{
  ST.TableLen = len + 1; // 实际申请11个元素的空间
  ST.elem = (ElemType *)malloc(sizeof(ElemType) * ST.TableLen);
  int i;
  srand(time(NULL));
  for (i = 0; i < ST.TableLen; i++)
  {
    ST.elem[i] = rand() % 100; //随机了11个数，但是第一个元素是没有用到的
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
  for (i = 2; i <= n; i++) // 第0个元素是哨兵，不用排序
  {
    if (A[i] < A[i - 1])
    {
      A[0] = A[i]; // 将A[i]放到第一个位置 也是哨兵
      for (j = i - 1; A[0] < A[j]; j--)
      {
        A[j + 1] = A[j]; //移动元素
      }
      A[j + 1] = A[0]; // 把暂存元素插入到对应位置
    }
  }
}

// 折半插入排序
void MidInsertSort(ElemType A[], int n)
{
  int i, j, low, high, mid;
  for (i = 2; i <= n; i++)
  {
    A[0] = A[i]; // 将A[i]放到第一个位置 也是哨兵
    low = 1;
    high = i - 1;       // low有序序列的开始，high有序序列的最后
    while (low <= high) // 先通过二分查找找到待插入位置
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
  for (dk = n / 2; dk >= 1; dk = dk / 2) //步长变化
  {
    for (i = dk + 1; i <= n; ++i) //以dk为步长进行插入排序
    {
      if (A[i] < A[i - dk])
      {
        A[0] = A[i]; // 哨兵
        for (j = i - dk; j > 0 && A[0] < A[j]; j = j - dk)
        {
          A[j + dk] = A[j];
        }
        A[j + dk] = A[0];
      }
    }
  }
}
//插入排序
int main()
{
  SSTable ST;
  ElemType A[10] = {64, 34, 25, 12, 22, 11, 90, 54, 67, 88};
  ST_Init(ST, 10); //实际申请了11个元素空间
  memcpy(ST.elem + 1, A, sizeof(A));
  ST_print(ST);

  // 直接插入排序
  // InsertSort(ST.elem, 10);

  // 折半插入排序
  // MidInsertSort(ST.elem, 10);

  // 希尔排序
  ShellSort(ST.elem, 10);
  ST_print(ST);
  return 0;
}
