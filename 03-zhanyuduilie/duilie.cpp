#include <stdio.h>
#include <stdlib.h>

#define MAXSize 5
typedef int ElemType;
typedef struct
{
  ElemType data[MAXSize];
  int front;
  int rear;
} SeqQueue;

void InitQueue(SeqQueue &Q)
{
  Q.front = Q.rear = 0;
}

bool IsEmpty(SeqQueue Q)
{
  if (Q.front == Q.rear)
  {
    return true;
  }
  return false;
}

bool EnQueue(SeqQueue &Q, ElemType e)
{
  if ((Q.rear + 1) % MAXSize == Q.front) // 如果队列满了，则不能插入
  {
    return false;
  }
  Q.data[Q.rear] = e;
  Q.rear = (Q.rear + 1) % MAXSize; // 将rear后移一位
  return true;
}

bool DeQueue(SeqQueue &Q, ElemType &e)
{
  // 等价于 if ((Q.rear + 1) % MAXSize == Q.front) // 如果队列满了，则不能插入
  if (Q.front == Q.rear) // 如果队列空了，则不能删除
  {
    return false;
  }
  e = Q.data[Q.front];
  Q.front = (Q.front + 1) % MAXSize; // 将front后移一位
  return true;
}
// 循环队列
int main()
{
  SeqQueue Q;
  bool ret;
  ElemType element;

  /* 初始化队列 */
  InitQueue(Q);

  /* 判空 */
  ret = IsEmpty(Q);
  if (ret)
  {
    printf("队列为空\n");
  }
  else
  {
    printf("队列不为空\n");
  }

  /* 入队 */
  EnQueue(Q, 1);
  EnQueue(Q, 2);
  EnQueue(Q, 3);
  EnQueue(Q, 4);
  ret = EnQueue(Q, 5);
  ret = EnQueue(Q, 6);
  if (ret)
  {
    printf("入队成功\n");
  }
  else
  {
    printf("入队失败\n");
  }

  /* 出队 */
  ret = DeQueue(Q, element);
  if (ret)
  {
    printf("出队成功，出队元素为%d\n", element);
  }
  else
  {
    printf("出队失败\n");
  }

  return 0;
}