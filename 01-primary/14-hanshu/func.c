
#include <stdio.h>
#include "func.h"

int print_star(int i)
{
  printf("*********");
  printf("print_star: %d\n", i);
  return i + 3;
}

void print_message()
{
  printf("i am ok \n");
  print_star(5);
}