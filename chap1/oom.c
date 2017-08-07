#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  unsigned long size = 0;
  char *buf = NULL;
  while (1) {
    char *cp = realloc(buf, size + 1048576);
    if (!cp)
      break;
    buf = cp;
    size += 1048576;
  }
  printf("Allocated %lu MB\n", size / 1048576);
  memset(buf, 0, size);
  printf("Filled %lu MB\n", size /1048576);
  free(buf);
  printf("Freed %lu MB\n", size / 1048576);
  return 0;
}
