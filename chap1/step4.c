#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int p, q;
  int ans;
  
  if (argc != 3){
    printf("[!] this program must to set two decimal argument");
  }

  p = atoi(argv[1]);
  q = atoi(argv[2]);

  puts("[*] Division test program");
  printf("p: %d, q: %d\n", p, q);

  ans = p /q;
  printf("p /q = %d", ans);
  return 0;
  
}
