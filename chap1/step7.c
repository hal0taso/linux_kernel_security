#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  unsigned long size = 0;
  char *buf = NULL;

  while (1) {
    // 1 MB = 1048576 byte
    char *cp = realloc(buf, size + 1048576);
    if (!cp){
      break;
    }
    buf = cp;
    size += 1048576;
  }
  printf("[*] Allocated %lu kB\n", size / 1024);

  memset(buf, 0, size);
  printf("[*] Filled %lu kB\n", size / 1024);
  
  free(buf);
  printf("[*] Freed %lu kB\n", size / 1024);
  return 0;
  
}
