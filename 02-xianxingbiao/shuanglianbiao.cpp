#include <stdio.h>
#include <stdlib.h>

typedef int ElemType; // 顺序表中元素的类型
typedef struct DNode
{
  int data;
  struct DNode *prior;
  struct DNode *next;
} DNode, *DLinkList;

// 头插法
DLinkList DListHeadInsert(DLinkList &DL)
{
  DNode *s;
  int x;
  DL = (DLinkList)malloc(sizeof(DNode)); // 创建带头结点的链表
  DL->prior = NULL;
  DL->next = NULL;
  scanf("%d", &x);
  // 3 4 5 6 9999
  while (x != 9999)
  {
    s = (DNode *)malloc(sizeof(DNode));
    s->data = x;
    s->next = DL->next;
    if (DL->next != NULL)
    {
      DL->next->prior = s;
    }
    s->prior = DL;
    DL->next = s;
    scanf("%d", &x);
  }
  return DL;
}

/* 尾插法 */
DLinkList DListTailInsert(DLinkList &DL)
{
  int x;
  DL = (DLinkList)malloc(sizeof(DNode)); // 创建带头结点的链表
  DLinkList s, r = DL;                   // r代表尾指针，指向最后一个节点
  DL->prior = NULL;
  DL->next = NULL;
  scanf("%d", &x);
  // 3 4 5 6 9999
  while (x != 9999)
  {
    s = (DLinkList)malloc(sizeof(DNode));
    s->data = x;
    r->next = s;
    s->prior = r;
    r = s; // r指向新的表尾结点
    scanf("%d", &x);
  }
  r->next = NULL; // 将最后一个节点的next指针指向NULL
  return DL;
}

/* 新节点插入第几个位置 头插法 */
DLinkList DListFrontInsert(DLinkList &DL, int i, ElemType e)
{
}

// 链表遍历打印
void PrintList(DLinkList L)
{
  DLinkList p = L->next;
  while (p != NULL)
  {
    printf("%3d", p->data); //打印当前节点数据
    p = p->next;            // 指向下一个节点
  }
  printf("\n");
}

// 双链表
int main()
{
  DLinkList DL;
  DLinkList search;

  /* 头插法 */
  // DListHeadInsert(DL);
  // PrintList(DL);

  /* 尾插法 */
  DListTailInsert(DL);
  PrintList(DL);

  /* 新节点插入第几个位置 头插法 */
  DListFrontInsert(DL, 2, 44);
  PrintList(DL);
}
