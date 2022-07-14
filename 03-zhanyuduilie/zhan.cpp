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
  Push(S, 3); // 入栈元素3
  Push(S, 4); // 入栈元素4
  Push(S, 5); // 入栈元素5

  return 0;
}