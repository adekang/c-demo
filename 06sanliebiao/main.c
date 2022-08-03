#include <stdio.h>

#define MaxKey 1000
// hash表
int hash(char *key)
{
  int h = 0, g;
  while (*key)
  {
    h = (h << 4) + *key++;
    g = h & 0xf0000000;
    if (g)
    {
      h ^= g >> 24;
    }
    h &= ~g;
  }
  return h % MaxKey;
}

// 散列表
int main()
{
  const char *pStr[5] = {"xiongda", "lele", "hanmeimei", "wangdao"};
  int i;
  const char *pHash_table[MaxKey] = {NULL}; //哈希表， 散列表
  for (i = 0; i < 5; i++)
  {
    printf("%s is key=%d\n", pStr[i], hash(pStr[i]));
    pHash_table[hash(pStr[i])] = pStr[i];
  }
  return 0;
}
