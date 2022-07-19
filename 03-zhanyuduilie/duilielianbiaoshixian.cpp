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
  Q.front->next = NULL; //始终为空
}

void EnQueue(LinkQueue &Q, ElemType x)
{
  LinkList s = (LinkList)malloc(sizeof(LinkNode));
  s->data = x;
  s->next = NULL;
  Q.rear->next = s; // rear 始终指向尾部
  Q.rear = s;
}
bool DeQueue(LinkQueue &Q, ElemType &e)
{
  if (Q.front == Q.rear)
  {
    // 队列为空
    return false;
  }

  LinkList p = Q.front->next; // 头节点什么也没有存 p指向队列的第一个元素
  Q.front->next = p->next;    //锻炼
  e = p->data;
  if (Q.rear == p) //删除的是最后一个位置
  {
    Q.rear = Q.front; // 队列值为空
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

// 队列链表实现
int main()
{
  LinkQueue Q;
  bool ret;
  ElemType element; // 存储出队元素
  // 初始化队列
  InitQueue(Q);
  // 入队
  EnQueue(Q, 1);
  EnQueue(Q, 2);
  EnQueue(Q, 3);
  // 出队
  ret = DeQueue(Q, element);
  if (ret)
  {
    printf("出队成功，元素为：%d\n", element);
  }
  else
  {
    printf("出队失败\n");
  }
  // 判空
  ret = IsEmpty(Q);
  if (ret)
  {
    printf("为空\n");
  }
  else
  {
    printf("不为空\n");
  }

  return 0;
}