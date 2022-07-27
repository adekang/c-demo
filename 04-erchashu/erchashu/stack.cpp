#include "function.h"

void InitStack(SqStack &S)
{
  S.top = -1;
}

bool Push(SqStack &S, ElemType i)
{
  if (S.top == MaxSize - 1)
  {
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
    return false;
  }
  m = S.data[S.top];
  return true;
}

bool Pop(SqStack &S, ElemType &m)
{
  if (S.top == -1)
  {
    return false;
  }
  m = S.data[S.top];
  S.top--;
  //  �ȼ���  m = S.data[S.top--];
  return true;
}
// �ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack &S)
{
  return S.top == -1; // ���ջΪ�գ��򷵻�true
}
