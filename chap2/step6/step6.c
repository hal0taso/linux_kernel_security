/*
  allocating memory dinamicaly by using kmalloc.

  kmalloc(8192, GFP_ATOMIC);
  --> stack trace�ФƤ�����
      kerneloops��ȯ�Ԥ��Ƥ��롩 --> NULL pointer dereference��ȯ�����Ƥ�����
                                 
*/

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL v2");

#define PAGESIZE 4096 * 2

void mset(char *buf, size_t size)
{
  int i;
  for(i = 0; i < size; i ++){
    *buf = 0UL;
    buf += sizeof(unsigned long);
  }
}

int step6_init(void)
{
  int size = PAGESIZE;
  void *ptr[0x100];

  
  printk(KERN_ALERT "step6 LOAD\n");
  
  ptr[0] = kmalloc(size, GFP_ATOMIC);
  if(ptr[0] == NULL){
    printk("break\n");

  }
  mset(ptr[0], size);
  printk("[%p] %d byte memory allocated.\n", ptr[0], size);      
  kfree(ptr[0]);  
    
  return 0;
}

void step6_exit(void)
{
  printk(KERN_ALERT "step6 UNLOADED\n");
}

module_init(step6_init);
module_exit(step6_exit);
