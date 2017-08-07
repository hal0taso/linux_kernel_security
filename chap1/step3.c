#include <stdio.h>

int main (int argc, char *argv[])
{
  int a, b, c;
  int *p;

  a = 5;
  printf("a is %d.\n", a);
  p = &a;
  printf("p is now point to a.\nand p value is %d.\n", *p);
  b = *p;
  printf("b is %d\n", b);
  p = NULL;
  printf("now, p is set to Null.\n");
  c = *p;
  printf("c is %d\n", c);

  return 0;
}
