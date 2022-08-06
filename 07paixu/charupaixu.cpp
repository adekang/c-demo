#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

//插入排序
int main()
{
  SSTable ST;
  ST_Init(ST, 10); //实际申请了11个元素空间
  ST_print(ST);
  InsertSort(ST.elem, 10);
  // MidInsertSort(ST.elem,10);
  // ShellSort(ST.elem,10);
  ST_print(ST);
  return 0;
}
