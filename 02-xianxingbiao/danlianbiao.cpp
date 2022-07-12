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
    s->next = L->next;                   // ���½���nextָ��ָ������ĵ�һ��Ԫ�أ���һ�����������ݵĽڵ㣩
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

// �����ӡ
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

  // CreatList1(L); // ͷ�巨�½�����
  CreatList2(L); // β�巨�½�����
  // PrintList(L);
  search = GetElem(L, 2); // ��������ڶ���λ�õ�Ԫ��
  if (search != NULL)
  {
    printf("���ҳɹ�\n");
    printf("%d\n", search->data);
  }
  return 0;
}