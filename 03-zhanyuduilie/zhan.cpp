#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;
typedef struct
{
  ElemType data[MaxSize]; // ����
  int top;
} SqStack;

void InitStack(SqStack &S)
{
  S.top = -1;
}

// �ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack S)
{
  return S.top == -1; // ���ջΪ�գ��򷵻�true
}

bool Push(SqStack &S, ElemType i)
{
  if (S.top == MaxSize - 1)
  {
    printf("ջ�����޷���ջ\n");
    return false;
  }
  S.top++;
  S.data[S.top] = i;
  // S.data[++S.top] = i;  // ������ȼ�
  return true;
}

/* ��ȡջ��λ�� */
bool GetTop(SqStack S, ElemType &m)
{
  if (S.top == -1)
  {
    printf("ջ�գ��޷�ȡջ��Ԫ��\n");
    return false;
  }
  m = S.data[S.top];
  return true;
}

bool Pop(SqStack &S, ElemType &m)
{
  if (S.top == -1)
  {
    printf("ջ�գ��޷�ȡջ��Ԫ��\n");
    return false;
  }
  m = S.data[S.top];
  S.top--;
  //  �ȼ���  m = S.data[S.top--];
  return true;
}
// ջ
int main()
{
  SqStack S;
  bool flag;
  ElemType m;

  /* ��ʼ��ջ */
  InitStack(S); // ��ʼ��ջ
  flag = StackEmpty(S);
  if (flag)
  {
    printf("ջΪ��\n");
  }

  /* ��ջ */
  Push(S, 3); // ��ջԪ��3
  Push(S, 4); // ��ջԪ��4
  Push(S, 5); // ��ջԪ��5

  /* ��ȡջ��λ�� */
  flag = GetTop(S, m);
  if (flag)
  {
    printf("ջ��Ԫ��Ϊ��%d\n", m);
  }

  /* ��ջ */
  flag = Pop(S, m);
  if (flag)
  {
    printf("������Ԫ��Ϊ��%d\n", m);
  }
  return 0;
}