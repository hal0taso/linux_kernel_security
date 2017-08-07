/*

  環境:
  $ uname -a
  Linux hal0taso 4.8.0-46-generic #49-Ubuntu SMP Fri Mar 31 13:57:14 UTC 2017 x86_64 x86_64 x86_64 GNU/Linu

  $ gcc -no-pie -fno-stack-protector step5.c -o step5 -Wall

  stack size(in gdb)          : 0x21000
  $ ulimit -s                 : 0x800000(8192 [Kbyte])
  stack size for each rstack(): 0x1020
  +--> size of buffer         : 0x1000
  ループは2029回実行可(2029*0x1020=0x7fcda0)
  gdbの中では2030回実行できる(2031を引数に渡すとSEGV)
  2030 --> 0x7fddc0
  2031 --> 0x7fede0
  gdbでSEGV起きたときのRSP - (1回目のaddr of buf): 0x7fddd0
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void rstack(int n)
{
  char buf[4096];
  //char *buf_ptr;
  
  //buf_ptr = buf;
  memset(&buf, '\x00' , sizeof(buf));


  printf("[%02d] addr buf: %p\n", n, &buf);

  n--;
  
  if (n == 0){
    exit(0);
  }
  rstack(n);
}

int main(int argc, char *argv[])

{

  if (argc != 2){
    perror("give me num of recursion.");
    exit(0);
  }
  
  rstack(atoi(argv[1]));
  
  return 0;
}
