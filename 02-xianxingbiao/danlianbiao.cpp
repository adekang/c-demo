#include <stdio.h>
#include <stdlib.h>

typedef int ElemType; // 顺序表中元素的类型

typedef struct LNode
{
  ElemType data;      // 数据域
  struct LNode *next; //指针域
} LNode, *LinkList;   // LNode 这里是别名 ； *LinkList 等价于 struct LNode*

// 头插法链表
LinkList CreatList1(LinkList &L)
{
  LNode *s;
  int x;
  L = (LinkList)malloc(sizeof(LNode)); //带头节点的链表
  L->next = NULL;                      // L->data里面没有数据
  scanf("%d", &x);                     //从标准输入读取数据
  while (x != 9999)
  {
    s = (LinkList)malloc(sizeof(LNode)); //创建新节点，申请一个新空间
    s->data = x;                         //把读取到的值赋值给新节点的data中
    s->next = L->next;                   // 让新结点的next指针指向链表的第一个元素（第一个放我们数据的节点）
    L->next = s;                         //将新节点插入到链表中
    scanf("%d", &x);
  }
  return L;
}

// 尾插法链表
LinkList CreatList2(LinkList &L)
{
  int x;
  L = (LinkList)malloc(sizeof(LNode)); //带头节点的链表
  LNode *s, *r = L;                    // LinkList s,r; 也可以
  scanf("%d", &x);                     //从标准输入读取数据
  while (x != 9999)
  {
    s = (LinkList)malloc(sizeof(LNode)); //创建新节点，申请一个新空间
    s->data = x;                         //把读取到的值赋值给新节点的data中
    r->next = s;                         //将新节点插入到链表中
    r = s;                               // r指向新节点，下次插入的位置
    scanf("%d", &x);
  }
  r->next = NULL; // 将最后一个节点的next指针指向空指针
  return L;
}

// 链表打印
void PrintList(LinkList L)
{
  LinkList p = L->next;
  while (p != NULL)
  {
    printf("%3d", p->data); //打印当前节点数据
    p = p->next;            // 指向下一个节点
  }
  printf("\n");
}

int main()
{
  LinkList L;      // 链表头是结构体指针类型；
  LinkList search; // 用来存储拿到的某一个节点

  // CreatList1(L); // 头插法新建链表
  CreatList2(L); // 尾插法新建链表
  PrintList(L);
  return 0;
}