#include <stdio.h>
#include <stdlib.h>

// 线性表
#define MaxSize 50
typedef int ElemType; // 顺序表中元素的类型

// 静态分配
typedef struct
{
  ElemType data[MaxSize];
  int length;
} SqList;

// 插入元素
bool ListInsert(SqList &L, int i, ElemType e)
{
  if (i < 1 || i > L.length + 1) // 判断要插入的位置是否合法
  {
    printf("error: i is out of range\n");
    return false;
  }
  if (L.length >= MaxSize) // 判断是否已经满了
  {
    printf("error: list is full\n");
    return false;
  }
  for (int j = L.length; j >= i; j--) // 移动顺序表中的元素，依次往后移动
  {
    L.data[j] = L.data[j - 1];
  }
  L.data[i - 1] = e;
  L.length++;
  return true;
}

// 删除第i个元素，并返回其值
// 删除使用元素e的引用的目的是拿出对应的值
bool ListDelete(SqList &L, int i, ElemType &e)
{
  if (i < 1 || i > L.length) // 判断删除的位置是不合法
  {
    printf("error: i is out of range\n");
    return false;
  }
  if (L.length == 0) // 顺序表中没有元素，无需删除
  {
    return false;
  }
  e = L.data[i - 1];                 // 将要删除的元素的值赋给e
  for (int j = i; j < L.length; j++) // 移动顺序表中的元素，依次往前移动
  {
    L.data[j - 1] = L.data[j];
  }
  L.length--; // 删除后顺序表的长度减1
  return true;
}
// 查找元素
int LocateElem(SqList L, ElemType e)
{
  for (int i = 0; i < L.length; i++) // 遍历顺序表
  {
    if (L.data[i] == e)
    {
      return i + 1; // 因为顺序表中的元素的下标是从1开始的，所以返回的是元素的下标+1
    }
  }
  return 0;
}
//  打印数组
void PrintList(SqList &L)
{
  for (int i = 0; i < L.length; i++)
  {
    // %3d 占用三个空格
    printf("%3d", L.data[i]);
  }
  printf("\n");
}

int main()
{
  SqList L;     // 定义一个顺序表L
  bool ret;     // 查看返回值
  ElemType del; // 用来存储要删除的元素

  // 初始化顺序表L
  L.data[0] = 1;
  L.data[1] = 2;
  L.data[2] = 3;
  L.data[3] = 60;
  L.length = 4;              // 顺序表的长度
  ret = ListInsert(L, 1, 4); // 在第1个位置插入4
  if (ret)
  {
    printf("插入成功\n");
    PrintList(L);
  }
  else
  {
    printf("插入失败\n");
    PrintList(L);
  }

  ret = ListDelete(L, 1, del); // 删除第1个元素
  if (ret)
  {
    printf("删除成功，删除的元素为%d\n", del);
    PrintList(L);
  }
  else
  {
    printf("删除失败\n");
    PrintList(L);
  }
  int elem_pos;
  elem_pos = LocateElem(L, 60); // 查找元素60的位置
  if (elem_pos)
  {
    printf("查找成功\n");
    printf("元素在第%d个位置\n", elem_pos);
  }
  else
  {
    printf("查找失败\n");
  }

  return 0;
}