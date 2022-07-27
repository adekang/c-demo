#include "function.h"

//带头节点的队列
void InitQueue(LinkQueue &Q)
{
  Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
  Q.front->next = NULL;
}

bool IsEmpty(LinkQueue &Q)
{
  if (Q.front == Q.rear)
  {
    return true;
  }
  return false;
}

void EnQueue(LinkQueue &Q, ElemType e)
{
  LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
  s->data = e;
  s->next = NULL;
  Q.rear->next = s;
  Q.rear = s;
}

bool DeQueue(LinkQueue &Q, ElemType &e)
{
  if (Q.front == Q.rear)
    return false;
  LinkNode *p = Q.front->next;
  e = p->data;
  Q.front->next = p->next;
  if (Q.rear == p)
  {
    Q.rear = Q.front;
  }
  free(p);
  return true;
}
