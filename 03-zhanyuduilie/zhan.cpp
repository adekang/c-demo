#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;
typedef struct
{
  ElemType data[MaxSize]; // 数组
  int top;
} SqStack;

void InitStack(SqStack &S)
{
  S.top = -1;
}

// 判断栈是否为空
bool StackEmpty(SqStack S)
{
  return S.top == -1; // 如果栈为空，则返回true
}

bool Push(SqStack &S, ElemType i)
{
  if (S.top == MaxSize - 1)
  {
    printf("栈满，无法入栈\n");
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
    printf("栈空，无法取栈顶元素\n");
    return false;
  }
  m = S.data[S.top];
  return true;
}

bool Pop(SqStack &S, ElemType &m)
{
  if (S.top == -1)
  {
    printf("栈空，无法取栈顶元素\n");
    return false;
  }
  m = S.data[S.top];
  S.top--;
  //  等价于  m = S.data[S.top--];
  return true;
}
// 栈
int main()
{
  SqStack S;
  bool flag;
  ElemType m;

  /* 初始化栈 */
  InitStack(S); // 初始化栈
  flag = StackEmpty(S);
  if (flag)
  {
    printf("栈为空\n");
  }

  /* 入栈 */
  Push(S, 3); // 入栈元素3
  Push(S, 4); // 入栈元素4
  Push(S, 5); // 入栈元素5

  /* 获取栈顶位置 */
  flag = GetTop(S, m);
  if (flag)
  {
    printf("栈顶元素为：%d\n", m);
  }

  /* 弹栈 */
  flag = Pop(S, m);
  if (flag)
  {
    printf("弹出的元素为：%d\n", m);
  }
  return 0;
}