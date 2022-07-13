#include <stdio.h>
#include <stdlib.h>

typedef int ElemType; // ˳�����Ԫ�ص�����

typedef struct LNode
{
  ElemType data;      // ������
  struct LNode *next; //ָ����
} LNode, *LinkList;   // LNode �����Ǳ��� �� *LinkList �ȼ��� struct LNode*

// ͷ�巨����
LinkList CreatList1(LinkList &L)
{
  LNode *s;
  int x;
  L = (LinkList)malloc(sizeof(LNode)); //��ͷ�ڵ������
  L->next = NULL;                      // L->data����û������
  scanf("%d", &x);                     //�ӱ�׼�����ȡ����
  while (x != 9999)
  {
    s = (LinkList)malloc(sizeof(LNode)); //�����½ڵ㣬����һ���¿ռ�
    s->data = x;                         //�Ѷ�ȡ����ֵ��ֵ���½ڵ��data��
    s->next = L->next;                   // ���½���nextָ��ָ�������ĵ�һ��Ԫ�أ���һ�����������ݵĽڵ㣩
    L->next = s;                         //���½ڵ���뵽������
    scanf("%d", &x);
  }
  return L;
}

// β�巨����
LinkList CreatList2(LinkList &L)
{
  int x;
  L = (LinkList)malloc(sizeof(LNode)); //��ͷ�ڵ������
  LNode *s, *r = L;                    // LinkList s,r; Ҳ����
  scanf("%d", &x);                     //�ӱ�׼�����ȡ����
  while (x != 9999)
  {
    s = (LinkList)malloc(sizeof(LNode)); //�����½ڵ㣬����һ���¿ռ�
    s->data = x;                         //�Ѷ�ȡ����ֵ��ֵ���½ڵ��data��
    r->next = s;                         //���½ڵ���뵽������
    r = s;                               // rָ���½ڵ㣬�´β����λ��
    scanf("%d", &x);
  }
  r->next = NULL; // �����һ���ڵ��nextָ��ָ���ָ��
  return L;
}

// ���Ҷ�Ӧλ�õĽڵ��ֵ
LinkList GetElem(LinkList L, int i)
{
  LinkList p;
  p = L->next;
  int j = 1;
  if (i == 0)
  {
    return L;
  }
  if (i < 1)
  {
    return NULL;
  }
  while (p && j < i)
  {
    p = p->next;
    j++;
  }
  return p;
}
// ��ֵ����
LinkList LocateLem(LinkList L, ElemType e)
{
  LinkList p = L->next;

  while (p && p->data != e)
  {
    p = p->next;
  }

  return p;
}

// ��ֵ����
bool ListFrontInsert(LinkList L, int i, ElemType e)
{
  LinkList p = GetElem(L, i - 1);
  if (p == NULL)
  {
    return false;
  }
  LinkList el = (LinkList)malloc(sizeof(LNode));
  el->data = e;

  el->next = p->next;
  p->next = el;
  return true;
}

// ɾ���ڵ�
bool DeleteElm(LinkList L, int i)
{
  LinkList p, q;

  p = GetElem(L, i - 1);
  if (p == NULL)
  {
    return false; //ɾ����λ�ò���
  }
  q = p->next;
  p->next = q->next;

  free(q);
  q = NULL; // ��ֹ��ΪҰָ��
  return true;
}
// ������ӡ
void PrintList(LinkList L)
{
  LinkList p = L->next;
  while (p != NULL)
  {
    printf("%3d", p->data); //��ӡ��ǰ�ڵ�����
    p = p->next;            // ָ����һ���ڵ�
  }
  printf("\n");
}

int main()
{
  LinkList L;      // ����ͷ�ǽṹ��ָ�����ͣ�
  LinkList search; // �����洢�õ���ĳһ���ڵ�

  /* ͷ�巨�½����� */
  // CreatList1(L); // ͷ�巨�½�����
  // PrintList(L);

  /* β�巨�½����� */
  CreatList2(L); // β�巨�½�����
  // PrintList(L);

  /* ���������ڶ���λ�õ�Ԫ�� */
  // search = GetElem(L, 2);   // ���������ڶ���λ�õ�Ԫ��
  // if (search != NULL)
  // {
  //   printf("���ҳɹ�\n");
  //   printf("%d\n", search->data);
  // }
  // else
  // {
  //   printf("����ʧ��\n");
  // }

  /* ��ֵ��ѯ */
  // search = LocateLem(L, 5); // ��ֵ��ѯ
  // if (search != NULL)
  // {
  //   printf("���ҳɹ�\n");
  //   printf("%d\n", search->data);
  // }
  // else
  // {
  //   printf("����ʧ��\n");
  // }

  /* �½������i��λ�� */
  // ListFrontInsert(L, 2, 66); //�½������i��λ��
  // PrintList(L);

  /* ���ɾ����i��λ�� */
  DeleteElm(L, 2); //�½������i��λ��
  PrintList(L);

  return 0;
}