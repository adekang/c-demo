#include "function.h"

void PreOrder(BiTree p)
{
  if (p != NULL)
  {
    putchar(p->c);
    PreOrder(p->lchild);
    PreOrder(p->rchild);
  }
}
void InOrder(BiTree p)
{
  if (p != NULL)
  {
    PreOrder(p->lchild);
    putchar(p->c);
    PreOrder(p->rchild);
  }
}
void PostOrder(BiTree p)
{
  if (p != NULL)
  {
    PreOrder(p->lchild);
    PreOrder(p->rchild);
    putchar(p->c);
  }
}

// 中序遍历非递归
void InOrder2(BiTree T)
{
  SqStack S;
  InitStack(S);
  BiTree p = T;

  while (p || !StackEmpty(S))
  {
    if (p)
    {
      Push(S, p);
      p = p->lchild;
    }
    else
    {
      Pop(S, p);
      putchar(p->c);
      p = p->rchild;
    }
  }
}

// 层次遍历
void LevelOrder(BiTree T)
{
  LinkQueue Q;  //辅助队列
  InitQueue(Q); // 初始化队列
  BiTree p;
  EnQueue(Q, T); // 树根入队
  while (!IsEmpty(Q))
  {
    DeQueue(Q, p);
    putchar(p->c);
    if (p->lchild != NULL)
    {
      EnQueue(Q, p->lchild);
    }
    if (p->rchild != NULL)
    {
      EnQueue(Q, p->rchild);
    }
  }
}

int main()
{
  BiTree pnew;
  int i, j, pos;
  char c;
  BiTree tree = NULL; //树根
  // phead 对头 ptail 队尾
  ptag_t phead = NULL, ptail = NULL, listpnew = NULL, pcur = NULL;
  while (scanf("%c", &c) != EOF)
  {
    if (c == '\n')
    {
      break;
    }
    pnew = (BiTree)calloc(1, sizeof(BiTNode));
    pnew->c = c;                                 //数据放进去
    listpnew = (ptag_t)calloc(1, sizeof(tag_t)); // 给队列节点申请空间
    listpnew->p = pnew;
    if (tree == NULL)
    {
      tree = pnew;
      phead = listpnew; // 队列头
      ptail = listpnew; // 队列尾
      pcur = listpnew;
      continue;
    }
    else
    {
      ptail->pnext = listpnew; //新节点放入链表，尾插法
      ptail = listpnew;        // 指向队列尾部
    }
    // pcur 始终指向要插入节点的位置
    // 如何把新节点放入树
    if (pcur->p->lchild == NULL) //把新结点放到要插入结点的左边
    {
      pcur->p->lchild = pnew;
    }
    else if (pcur->p->rchild == NULL) //把新结点放到要插入结点的右边
    {
      pcur->p->rchild = pnew;
      pcur = pcur->pnext; // pcur 左右都放了结点后，pcur指向下一个
    }
  }

  // abcdefghij

  printf("\n----先序遍历---\n");
  // 先打印当前结点，打印左孩子，打印右孩子
  PreOrder(tree);

  printf("\n----中序遍历---\n");
  // 先打印左孩子，打印父亲，打印右孩子
  InOrder(tree);

  printf("\n----后序遍历---\n");
  // 先打印左孩子，打印右孩子，最后打印父亲
  PostOrder(tree);

  printf("\n----中序非递归遍历---\n");
  // 先打印左孩子，打印父亲，打印右孩子
  InOrder2(tree);

  printf("\n----层次遍历---\n");
  // 先打印左孩子，打印父亲，打印右孩子
  LevelOrder(tree);
  return 0;
}