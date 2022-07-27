#include <stdio.h>
#include <stdlib.h>

typedef char BiElemType;
typedef struct BiTNode
{
  BiElemType c; //�鼮�ϵ�data
  struct BiTNode *lchild;
  struct BiTNode *rchild;
} BiTNode, *BiTree;

typedef struct tag
{
  BiTree p;
  struct tag *pnext;
} tag_t, *ptag_t;

// ջ���
#define MaxSize 50
typedef BiTree ElemType;
typedef struct
{
  ElemType data[MaxSize];
  int top;
} SqStack;

void InitStack(SqStack &S);
bool Push(SqStack &S, ElemType x);
bool Pop(SqStack &S, ElemType &x);
bool StackEmpty(SqStack &S);
bool GetTop(SqStack &s, ElemType &x);

// �������
typedef struct LinkNode
{
  ElemType data;
  struct LinkNode *next;
} LinkNode;

typedef struct
{
  LinkNode *front, *rear;
} LinkQueue;

void InitQueue(LinkQueue &Q);
bool IsEmpty(LinkQueue &Q);
bool DeQueue(LinkQueue &Q, ElemType &e);
void EnQueue(LinkQueue &Q, ElemType e);