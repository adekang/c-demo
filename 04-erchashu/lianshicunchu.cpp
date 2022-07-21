#include <stdio.h>
#include <stdlib.h>

typedef char BiElemType;
typedef struct BiTNode
{
  BiElemType c; //�鼮�ϵ�data
  struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef struct tag
{
  BiTree p; // ����ĳ���ڵ�ĵ�ֵַ
  struct tag *next;
} tag_t, *ptag_t;

int main()
{
  BiTree pnew;
  int i, j, pos;
  char c;
  BiTree tree = NULL; //����
  // phead ��ͷ ptail ��β
  ptag_t phead = NULL, ptail = NULL, listpnew, pcur;
  while (scanf("%c", &c) != EOF)
  {
    if (c == '\n')
    {
      continue;
    }
    pnew = (BiTree)calloc(1, sizeof(BiTNode));
    pnew->c = c;                                 //���ݷŽ�ȥ
    listpnew = (ptag_t)calloc(1, sizeof(tag_t)); // �����нڵ�����ռ�
    listpnew->p = pnew;
    if (tree == NULL)
    {
      tree = pnew;
      phead = listpnew; // ����ͷ
      ptail = listpnew; // ����β
      pcur = listpnew;
      continue;
    }
    else
    {
      ptail->next = listpnew; //�½ڵ��������β�巨
      ptail = listpnew;       // ָ�����β��
    }
    // pcur ʼ��ָ��Ҫ����ڵ��λ��
    // ��ΰ��½ڵ������
    if (pcur->p->lchild == NULL) //���½��ŵ�Ҫ����������
    {
      pcur->p->lchild = pnew;
    }
    else if (pcur->p->rchild == NULL) //���½��ŵ�Ҫ��������ұ�
    {
      pcur->p->rchild = pnew;
      pcur = pcur->next; // pcur ���Ҷ����˽���pcurָ����һ��
    }
  }

  // abcdefg
  // preOrder(tree);
  return 0;
}