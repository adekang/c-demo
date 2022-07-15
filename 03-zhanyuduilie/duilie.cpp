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
  if ((Q.rear + 1) % MAXSize == Q.front) // ����������ˣ����ܲ���
  {
    return false;
  }
  Q.data[Q.rear] = e;
  Q.rear = (Q.rear + 1) % MAXSize; // ��rear����һλ
  return true;
}

bool DeQueue(SeqQueue &Q, ElemType &e)
{
  // �ȼ��� if ((Q.rear + 1) % MAXSize == Q.front) // ����������ˣ����ܲ���
  if (Q.front == Q.rear) // ������п��ˣ�����ɾ��
  {
    return false;
  }
  e = Q.data[Q.front];
  Q.front = (Q.front + 1) % MAXSize; // ��front����һλ
  return true;
}
// ѭ������
int main()
{
  SeqQueue Q;
  bool ret;
  ElemType element;

  /* ��ʼ������ */
  InitQueue(Q);

  /* �п� */
  ret = IsEmpty(Q);
  if (ret)
  {
    printf("����Ϊ��\n");
  }
  else
  {
    printf("���в�Ϊ��\n");
  }

  /* ��� */
  EnQueue(Q, 1);
  EnQueue(Q, 2);
  EnQueue(Q, 3);
  EnQueue(Q, 4);
  ret = EnQueue(Q, 5);
  ret = EnQueue(Q, 6);
  if (ret)
  {
    printf("��ӳɹ�\n");
  }
  else
  {
    printf("���ʧ��\n");
  }

  /* ���� */
  ret = DeQueue(Q, element);
  if (ret)
  {
    printf("���ӳɹ�������Ԫ��Ϊ%d\n", element);
  }
  else
  {
    printf("����ʧ��\n");
  }

  return 0;
}