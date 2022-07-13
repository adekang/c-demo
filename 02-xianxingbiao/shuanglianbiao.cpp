#include <stdio.h>
#include <stdlib.h>

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
  DListHeadInsert(DL);
  PrintList(DL);
}
