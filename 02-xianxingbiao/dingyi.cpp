#include <stdio.h>
#include <stdlib.h>

// ���Ա�
#define MaxSize 50
typedef int ElemType; // ˳�����Ԫ�ص�����

// ��̬����
typedef struct
{
  ElemType data[MaxSize];
  int length;
} SqList;

// ����Ԫ��
bool ListInsert(SqList &L, int i, ElemType e)
{
  if (i < 1 || i > L.length + 1) // �ж�Ҫ�����λ���Ƿ�Ϸ�
  {
    printf("error: i is out of range\n");
    return false;
  }
  if (L.length >= MaxSize) // �ж��Ƿ��Ѿ�����
  {
    printf("error: list is full\n");
    return false;
  }
  for (int j = L.length; j >= i; j--) // �ƶ�˳����е�Ԫ�أ����������ƶ�
  {
    L.data[j] = L.data[j - 1];
  }
  L.data[i - 1] = e;
  L.length++;
  return true;
}

// ɾ����i��Ԫ�أ���������ֵ
// ɾ��ʹ��Ԫ��e�����õ�Ŀ�����ó���Ӧ��ֵ
bool ListDelete(SqList &L, int i, ElemType &e)
{
  if (i < 1 || i > L.length) // �ж�ɾ����λ���ǲ��Ϸ�
  {
    printf("error: i is out of range\n");
    return false;
  }
  if (L.length == 0) // ˳�����û��Ԫ�أ�����ɾ��
  {
    return false;
  }
  e = L.data[i - 1];                 // ��Ҫɾ����Ԫ�ص�ֵ����e
  for (int j = i; j < L.length; j++) // �ƶ�˳����е�Ԫ�أ�������ǰ�ƶ�
  {
    L.data[j - 1] = L.data[j];
  }
  L.length--; // ɾ����˳���ĳ��ȼ�1
  return true;
}
// ����Ԫ��
int LocateElem(SqList L, ElemType e)
{
  for (int i = 0; i < L.length; i++) // ����˳���
  {
    if (L.data[i] == e)
    {
      return i + 1; // ��Ϊ˳����е�Ԫ�ص��±��Ǵ�1��ʼ�ģ����Է��ص���Ԫ�ص��±�+1
    }
  }
  return 0;
}
//  ��ӡ����
void PrintList(SqList &L)
{
  for (int i = 0; i < L.length; i++)
  {
    // %3d ռ�������ո�
    printf("%3d", L.data[i]);
  }
  printf("\n");
}

int main()
{
  SqList L;     // ����һ��˳���L
  bool ret;     // �鿴����ֵ
  ElemType del; // �����洢Ҫɾ����Ԫ��

  // ��ʼ��˳���L
  L.data[0] = 1;
  L.data[1] = 2;
  L.data[2] = 3;
  L.data[3] = 60;
  L.length = 4;              // ˳���ĳ���
  ret = ListInsert(L, 1, 4); // �ڵ�1��λ�ò���4
  if (ret)
  {
    printf("����ɹ�\n");
    PrintList(L);
  }
  else
  {
    printf("����ʧ��\n");
    PrintList(L);
  }

  ret = ListDelete(L, 1, del); // ɾ����1��Ԫ��
  if (ret)
  {
    printf("ɾ���ɹ���ɾ����Ԫ��Ϊ%d\n", del);
    PrintList(L);
  }
  else
  {
    printf("ɾ��ʧ��\n");
    PrintList(L);
  }
  int elem_pos;
  elem_pos = LocateElem(L, 60); // ����Ԫ��60��λ��
  if (elem_pos)
  {
    printf("���ҳɹ�\n");
    printf("Ԫ���ڵ�%d��λ��\n", elem_pos);
  }
  else
  {
    printf("����ʧ��\n");
  }

  return 0;
}