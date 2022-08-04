#include <stdio.h>
#include <string.h>
typedef char *SString;

//Ϊʲô��1λ�ÿ�ʼ�Ƚϣ���Ϊ0��λ�ô洢���ַ����ĳ���
int Index(SString S, SString T)
{
  int i = 1, j = 1;
  while (i <= S[0] && j <= T[0])
  {
    if (S[i] == T[j])
    {
      ++i, ++j; //�����ȽϺ����ַ�
    }
    else
    {
      i = i - j + 2;
      j = 1; //ָ��������¿�ʼƥ��
    }
  }
  if (j > T[0])
    return i - T[0]; //ƥ��ɹ�
  else
    return 0;
}

void get_next(char T[], int next[])
{
  int i = 1, j = 0;
  next[1] = 0;
  while (i < T[0]) // iΪ�������±꣬jΪģʽ�����±�
  {
    if (j == 0 || T[i] == T[j])
    {
      ++i, ++j;
      next[i] = j;
    }
    else
      j = next[j];
  }
}

int KMP(SString S, SString T)
{
  int next[100];
  get_next(T, next);
  int i = 1, j = 1;
  while (i <= S[0] && j <= T[0])
  {
    if (j == 0 || S[i] == T[j])
    {
      ++i, ++j;
    }
    else
      j = next[j];
  }
  if (j > T[0])
    return i - T[0];
  else
    return 0;
}

int main()
{
  //�ַ������г�ʼ��
  char S[256];
  char T[10];
  int next[10];
  int pos;
  S[0] = strlen("abcabaaabaabcac"); // strlen���ж��ٸ��ַ�
  strcpy(S + 1, "abcabaaabaabcac");
  T[0] = strlen("abaabcac");
  strcpy(T + 1, "abaabcac");
  pos = Index(S, T);
  if (pos)
  {
    printf("%d\n", pos);
  }
  else
  {
    printf("not found\n");
  }
  get_next(T, next);
  pos = KMP(S, T);
  if (pos)
  {
    printf("%d\n", pos);
  }
  else
  {
    printf("not found\n");
  }
}