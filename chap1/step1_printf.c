#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  if(argc != 2){
    printf("[!] Error: set argument.");
    exit(0); 
  }
  printf("Hello, %s.", argv[1]);
  return 0;
}
