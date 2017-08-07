#include <stdio.h>

int main(int argc, char *argv[]){
  char buf[256] = "Hello, world.\n";

  fwrite(buf, sizeof(buf), 1, stdout);
  
  return 0;
}
