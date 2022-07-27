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
  // S.data[++S.top] = i;  // 与这个等价
  return true;
}

/* 获取栈顶位置 */
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
  //  等价于  m = S.data[S.top--];
  return true;
}
// 判断栈是否为空
bool StackEmpty(SqStack &S)
{
  return S.top == -1; // 如果栈为空，则返回true
}
