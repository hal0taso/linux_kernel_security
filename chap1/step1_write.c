#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{

  char buf[256] = "Hello, world\n";

  write(1, buf, sizeof(buf));

  return 0;
  
}
