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

// ��������ǵݹ�
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

// ��α���
void LevelOrder(BiTree T)
{
  LinkQueue Q;  //��������
  InitQueue(Q); // ��ʼ������
  BiTree p;
  EnQueue(Q, T); // �������
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
  BiTree tree = NULL; //����
  // phead ��ͷ ptail ��β
  ptag_t phead = NULL, ptail = NULL, listpnew = NULL, pcur = NULL;
  while (scanf("%c", &c) != EOF)
  {
    if (c == '\n')
    {
      break;
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
      ptail->pnext = listpnew; //�½ڵ����������β�巨
      ptail = listpnew;        // ָ�����β��
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
      pcur = pcur->pnext; // pcur ���Ҷ����˽���pcurָ����һ��
    }
  }

  // abcdefghij

  printf("\n----�������---\n");
  // �ȴ�ӡ��ǰ��㣬��ӡ���ӣ���ӡ�Һ���
  PreOrder(tree);

  printf("\n----�������---\n");
  // �ȴ�ӡ���ӣ���ӡ���ף���ӡ�Һ���
  InOrder(tree);

  printf("\n----�������---\n");
  // �ȴ�ӡ���ӣ���ӡ�Һ��ӣ�����ӡ����
  PostOrder(tree);

  printf("\n----����ǵݹ����---\n");
  // �ȴ�ӡ���ӣ���ӡ���ף���ӡ�Һ���
  InOrder2(tree);

  printf("\n----��α���---\n");
  // �ȴ�ӡ���ӣ���ӡ���ף���ӡ�Һ���
  LevelOrder(tree);
  return 0;
}