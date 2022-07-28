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
    // 为新节点申请空间，第一个结点作为树根
    T = (BiTree)malloc(sizeof(BSTNode));
    T->key = k;
    T->lchild = T->rchild = NULL;
    return 1; // 插入成功
  }
  else if (k == T->key)
  {
    return 0; // 发现相同的元素，插入失败
  }
  else if (k < T->key) //如果要插入的节点，小于当前节点就放在左子树
  {
    return BST_Insert(T->lchild, k); //函数调用结束后，左孩子和原来的父亲会关联起来
  }
  else // 相反就方右子树
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
    BST_Insert(T, str[i]); //把某一个节点插入到二叉排序树中
    i++;
  }
}

BSTNode *BST_Search(BiTree T, KeyType key, BiTree &p)
{
  p = NULL;
  while (T != NULL && key != T->key)
  {
    // p 存储要找到节点的父节点
    p = T;
    if (key < T->key) //比当前节点小，就左边找
    {
      T = T->lchild;
    }
    else //比当前节点大，就右边找
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
      // 左右子树都不为空
      // 一般的删除策略是左子树的最大数据或右子树的最小数据代替要删除的节点
      // 这里采用左子树最大数代替
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
  // 中序遍历
  InOrder(T);
  printf("\n");
  // 查找节点
  search = BST_Search(T, 40, parent);
  if (search)
  {
    printf("%c所在的结点是%d\n", 40, search->key);
  }
  else
  {
    printf("%c不存在\n", 40);
  }
  // 删除节点
  DeleteNode(T, 66);
  InOrder(T);
  return 0;
}
