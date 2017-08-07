/*

  $ gcc -no-pie step6.c -o step6 -Wall -fno-stack-protector

  0x100000000 --> 4Gbyte ������Ƥ��顢�ޥ����ߤޤä���gui���ץ꤬ư���ʤ��ʤä�������ư�������Ȥ���ȤȤƤ�Ť��ä�(swap����Ƥ���??)
  
  0x300000000 --> 12 Gbyte ���Ʊ����
  0x400000000 --> 16 Gbyte SEGV����

  ���δ֤��餤..?

  0x380000000 --> 14 Gbyte SEGV����
  0x340000000 --> 13 Gbyte ư��
  0x360000000 --> 13.5 Gbyte ư��(chrome�ȤäƤ����SEGV)
  0x370000000 --> 13.75 Gbyte ư��(chrome�ȤäƤ���SEGV)
  0x37fffffff --> ư����.

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
