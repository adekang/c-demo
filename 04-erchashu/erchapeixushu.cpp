#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef struct BSTNode
{
  KeyType key;
  struct BSTNode *lchild, *rchild;
} BSTNode, *BiTree;

int BST_Insert(BiTree &T, KeyType k)
{
  if (T == NULL)
  {
    // Ϊ�½ڵ�����ռ䣬��һ�������Ϊ����
    T = (BiTree)malloc(sizeof(BSTNode));
    T->key = k;
    T->lchild = T->rchild = NULL;
    return 1; // ����ɹ�
  }
  else if (k == T->key)
  {
    return 0; // ������ͬ��Ԫ�أ�����ʧ��
  }
  else if (k < T->key) //���Ҫ����Ľڵ㣬С�ڵ�ǰ�ڵ�ͷ���������
  {
    return BST_Insert(T->lchild, k); //�������ý��������Ӻ�ԭ���ĸ��׻��������
  }
  else // �෴�ͷ�������
  {
    return BST_Insert(T->rchild, k);
  }
}

void Creat_BST(BiTree &T, KeyType str[], int n)
{
  T = NULL;
  int i = 0;
  while (i < n)
  {
    BST_Insert(T, str[i]); //��ĳһ���ڵ���뵽������������
    i++;
  }
}

BSTNode *BST_Search(BiTree T, KeyType key, BiTree &p)
{
  p = NULL;
  while (T != NULL && key != T->key)
  {
    // p �洢Ҫ�ҵ��ڵ�ĸ��ڵ�
    p = T;
    if (key < T->key) //�ȵ�ǰ�ڵ�С���������
    {
      T = T->lchild;
    }
    else //�ȵ�ǰ�ڵ�󣬾��ұ���
    {
      T = T->rchild;
    }
  }
  return T;
}

void DeleteNode(BiTree &root, KeyType x)
{
  if (root == NULL)
  {
    return;
  }

  if (x < root->key)
  {
    DeleteNode(root->lchild, x);
  }
  else if (x > root->key)
  {
    DeleteNode(root->rchild, x);
  }
  else
  {
    if (root->lchild == NULL)
    {
      BiTree temp = root;
      root = root->rchild;
      free(temp);
    }
    else if (root->rchild == NULL)
    {
      BiTree temp = root;
      root = root->lchild;
      free(temp);
    }
    else
    {
      // ������������Ϊ��
      // һ���ɾ����������������������ݻ�����������С���ݴ���Ҫɾ���Ľڵ�
      // ����������������������
      BiTree temp = root->lchild;
      if (temp->rchild != NULL)
      {
        temp = temp->rchild;
      }
      root->key = temp->key;
      DeleteNode(root->lchild, temp->key);
    }
  }
}

void InOrder(BiTree T)
{
  if (T != NULL)
  {
    InOrder(T->lchild);
    printf("%3d", T->key);
    InOrder(T->rchild);
  }
}

int main()
{
  BiTree T;
  BiTree parent;
  BiTree search;

  KeyType str[] = {54, 20, 66, 40, 28, 79, 58};
  Creat_BST(T, str, 7);
  // �������
  InOrder(T);
  printf("\n");
  // ���ҽڵ�
  search = BST_Search(T, 40, parent);
  if (search)
  {
    printf("%c���ڵĽ����%d\n", 40, search->key);
  }
  else
  {
    printf("%c������\n", 40);
  }
  // ɾ���ڵ�
  DeleteNode(T, 66);
  InOrder(T);
  return 0;
}
