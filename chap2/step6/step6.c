/*
  allocating memory dinamicaly by using kmalloc.

  kmalloc(8192);
  --> slabinfo 見ると4つまでallocateできそう -> 32個allocateできた
  kmalloc(4096); --> いける
*/

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL v2");

#define PAGESIZE 4092

void mset(char *buf, size_t size)
{
  int i;
  for(i = 0; i < size/sizeof(unsigned long long int); i ++){
    *buf = 0ULL;
    buf += sizeof(unsigned long long int);
  }
}

int step6_init(void)
{
  int size = PAGESIZE;
  unsigned long long int a_ptr[33];
  int i;
  
  printk(KERN_ALERT "step6 LOAD\n");
  for(i = 0; i < 32; i ++){
    a_ptr[i] = (unsigned long long int)kmalloc(size, GFP_KERNEL);
    if(a_ptr[i] == 0){
      printk("break\n");
      break;
    }
    mset((void *)a_ptr[i], size);
    printk("[%p] %d byte memory allocated(a_ptr[%d])\n", (void *)a_ptr[i], size, i);
    kfree((void *)a_ptr[i]);
    size *= 2;
  }
  /*
  for(i = 0; i < 32; i ++){
    kfree((void *)a_ptr[i]);  
  }
  */
  return 0;
}

void step6_exit(void)
{
  printk(KERN_ALERT "step6 UNLOADED\n");
}

module_init(step6_init);
module_exit(step6_exit);
