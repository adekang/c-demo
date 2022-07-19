#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LinkNode
{
  ElemType data;
  struct LinkNode *next;
} LinkNode, *LinkList;

typedef struct
{
  LinkList front;
  LinkList rear;
} LinkQueue;

void InitQueue(LinkQueue &Q)
{
  Q.front = Q.rear = (LinkList)malloc(sizeof(LinkNode));
  Q.front->next = NULL; //ʼ��Ϊ��
}

void EnQueue(LinkQueue &Q, ElemType x)
{
  LinkList s = (LinkList)malloc(sizeof(LinkNode));
  s->data = x;
  s->next = NULL;
  Q.rear->next = s; // rear ʼ��ָ��β��
  Q.rear = s;
}
bool DeQueue(LinkQueue &Q, ElemType &e)
{
  if (Q.front == Q.rear)
  {
    // ����Ϊ��
    return false;
  }

  LinkList p = Q.front->next; // ͷ�ڵ�ʲôҲû�д� pָ����еĵ�һ��Ԫ��
  Q.front->next = p->next;    //����
  e = p->data;
  if (Q.rear == p) //ɾ���������һ��λ��
  {
    Q.rear = Q.front; // ����ֵΪ��
  }
  free(p);
  return true;
}

bool IsEmpty(LinkQueue Q)
{
  if (Q.rear == Q.front)
  {
    return true;
  }
  return false;
}

// ��������ʵ��
int main()
{
  LinkQueue Q;
  bool ret;
  ElemType element; // �洢����Ԫ��
  // ��ʼ������
  InitQueue(Q);
  // ���
  EnQueue(Q, 1);
  EnQueue(Q, 2);
  EnQueue(Q, 3);
  // ����
  ret = DeQueue(Q, element);
  if (ret)
  {
    printf("���ӳɹ���Ԫ��Ϊ��%d\n", element);
  }
  else
  {
    printf("����ʧ��\n");
  }
  // �п�
  ret = IsEmpty(Q);
  if (ret)
  {
    printf("Ϊ��\n");
  }
  else
  {
    printf("��Ϊ��\n");
  }

  return 0;
}