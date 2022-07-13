#include <stdio.h>
#include <stdlib.h>

typedef int ElemType; // ˳�����Ԫ�ص�����
typedef struct DNode
{
  int data;
  struct DNode *prior;
  struct DNode *next;
} DNode, *DLinkList;

// ͷ�巨
DLinkList DListHeadInsert(DLinkList &DL)
{
  DNode *s;
  int x;
  DL = (DLinkList)malloc(sizeof(DNode)); // ������ͷ��������
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

/* β�巨 */
DLinkList DListTailInsert(DLinkList &DL)
{
  int x;
  DL = (DLinkList)malloc(sizeof(DNode)); // ������ͷ��������
  DLinkList s, r = DL;                   // r����βָ�룬ָ�����һ���ڵ�
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
    r = s; // rָ���µı�β���
    scanf("%d", &x);
  }
  r->next = NULL; // �����һ���ڵ��nextָ��ָ��NULL
  return DL;
}

/* �½ڵ����ڼ���λ�� ͷ�巨 */
DLinkList DListFrontInsert(DLinkList &DL, int i, ElemType e)
{
}

// ���������ӡ
void PrintList(DLinkList L)
{
  DLinkList p = L->next;
  while (p != NULL)
  {
    printf("%3d", p->data); //��ӡ��ǰ�ڵ�����
    p = p->next;            // ָ����һ���ڵ�
  }
  printf("\n");
}

// ˫����
int main()
{
  DLinkList DL;
  DLinkList search;

  /* ͷ�巨 */
  // DListHeadInsert(DL);
  // PrintList(DL);

  /* β�巨 */
  DListTailInsert(DL);
  PrintList(DL);

  /* �½ڵ����ڼ���λ�� ͷ�巨 */
  DListFrontInsert(DL, 2, 44);
  PrintList(DL);
}
