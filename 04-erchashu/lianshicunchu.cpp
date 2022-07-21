#include <stdio.h>
#include <stdlib.h>

typedef char BiElemType;
typedef struct BiTNode
{
  BiElemType c; //书籍上的data
  struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef struct tag
{
  BiTree p; // 树的某个节点的地址值
  struct tag *next;
} tag_t, *ptag_t;

int main()
{
  BiTree pnew;
  int i, j, pos;
  char c;
  BiTree tree = NULL; //树根
  // phead 对头 ptail 队尾
  ptag_t phead = NULL, ptail = NULL, listpnew, pcur;
  while (scanf("%c", &c) != EOF)
  {
    if (c == '\n')
    {
      continue;
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
      ptail->next = listpnew; //新节点放入链表，尾插法
      ptail = listpnew;       // 指向队列尾部
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
      pcur = pcur->next; // pcur 左右都放了结点后，pcur指向下一个
    }
  }

  // abcdefg
  // preOrder(tree);
  return 0;
}