/*

  $ gcc -no-pie step6.c -o step6 -Wall -fno-stack-protector

  0x100000000 --> 4Gbyte 割り当てたら、マウス止まった。guiアプリが動かなくなった。再度動かそうとするととても重かった(swapされている??)
  
  0x300000000 --> 12 Gbyte 上と同じ。
  0x400000000 --> 16 Gbyte SEGVした

  この間くらい..?

  0x380000000 --> 14 Gbyte SEGVした
  0x340000000 --> 13 Gbyte 動く
  0x360000000 --> 13.5 Gbyte 動く(chrome使っているとSEGV)
  0x370000000 --> 13.75 Gbyte 動く(chrome使っているSEGV)
  0x37fffffff --> 動いた.

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
 
  int *m_ptr;
  long long unsigned int m_size;
  
  if(argc != 2){
    perror("[!] usage: ./step6 [size(hex)]");
    exit(0);
  }

  m_size  = strtoull(argv[1], NULL, 16);

  m_ptr = (int *) malloc(m_size);
  memset(m_ptr, 0, m_size);

  printf("[*] malloc allocated 0x%llx size buffer at %p\n", m_size, m_ptr);

  free(m_ptr);
  
  return 0;
}
