/*
  allocating memory dinamicaly by using kmalloc.
*/

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL v2");


void mset(char *buf, size_t size)
{
  int i;
  for(i = 0; i < size; i ++){
    *buf = (char) 0;
    buf += sizeof(char);
  }
}

int step6_init(void)
{
  int size = 4096;
  int i;
  int j = 1;
  char *ptr;
  
  printk(KERN_ALERT "step6 LOAD\n");
  while(1){
    ptr = kmalloc(size*j, GFP_ATOMIC);
    if(ptr == NULL){
      break;
    }
    mset(ptr, size*j);
    printk("[%p] %d size memory allocated.\n", ptr, size);      
    kfree(ptr);
  }
  for(i = 10; i > 0; i --){
    while(1){
      ptr = kmalloc(size, GFP_ATOMIC);
      if(ptr == NULL){
        printk("break\n");
        break;
      }
      mset(ptr, size);
      printk("[%p] %d size memory allocated.\n", ptr, size);
    }
    size /= 2;
  }
  
  return 0;
}

void step6_exit(void)
{
  printk(KERN_ALERT "step6 UNLOADED\n");
}

module_init(step6_init);
module_exit(step6_exit);
